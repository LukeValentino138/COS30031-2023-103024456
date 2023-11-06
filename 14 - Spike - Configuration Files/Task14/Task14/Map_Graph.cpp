#include "Map_Graph.h"
#include "PickUpAction.h"
#include "InspectContentsAction.h"
#include "HealAction.h"
#include "DropItemAction.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

void Map_Graph::loadPlayer(Player* player, int initialHealth) {
    HealthAttribute* healthAttribute = new HealthAttribute(initialHealth);
    player->addComponent("Health", healthAttribute);
}

void Map_Graph::add_vertex(const std::string& name, const std::string& description) {
    vmap::iterator itr = vertices.find(name);
    if (itr == vertices.end()) {
        Vertex* v;
        v = new Vertex(name, description);
        vertices[name] = v;
        return;
    }
    printf("Nope. Vertex [%s] already exist!\n", name.c_str());
}

void Map_Graph::add_edge(const std::string& from, const std::string& to, const std::string& direction) {
    Vertex* f = (vertices.find(from)->second);
    Vertex* t = (vertices.find(to)->second);
    std::pair<std::string, Vertex*> edge = std::make_pair(direction, t);
    f->adj.push_back(edge);
}

void Map_Graph::print() {
    for (auto n : vertices) {
        n.second->print();
    }
}

void Map_Graph::load_map(const std::string& filename, Player* currentPlayer) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error, cannot open file: " << filename << std::endl;
        return;
    }

    nlohmann::json jsonObject;
    file >> jsonObject;

    std::string startingLocation = jsonObject["startingLocation"];



    for (const auto& location : jsonObject["locations"]) {
        add_vertex(location["name"], location["description"]);
        if (location.contains("entities")) {
            for (const auto& entityData : location["entities"]) {
                Entity* entity = nullptr;
                if (entityData["type"] == "simple") {
                    entity = new SimpleEntity(entityData["name"], entityData["description"]);
                }
                else if (entityData["type"] == "composite") {
                    entity = new ContainerEntity(entityData["name"], entityData["description"]);
                    if (entityData.contains("contains")) {
                        for (const auto& containedEntityData : entityData["contains"]) {
                            SimpleEntity* simpleEntity = new SimpleEntity(containedEntityData["name"], containedEntityData["description"]);
                            dynamic_cast<ContainerEntity*>(entity)->addChild(simpleEntity);
                        }
                    }
                }

                // Add actions to the entity
                if (entityData.contains("actions")) {
                    for (const auto& action : entityData["actions"]) {
                        if (action.is_string()) {
                            if (action == "pickup") {
                                entity->addComponent("Pick Up", new PickUpAction(currentPlayer, entity, this));
                            }
                            else if (action == "drop") {
                                entity->addComponent("Drop", new DropItemAction(currentPlayer, entity, this));
                            }
                            else if (action == "inspect") {
                                entity->addComponent("Inspect Contents", new InspectContentsAction(dynamic_cast<ContainerEntity*>(entity)));
                            }
                            // Other string-based actions can be added here
                            else if (action == "healAction") {
                                HealthAttribute* playerHealth = dynamic_cast<HealthAttribute*>(currentPlayer->getComponent("Health"));
                                if (playerHealth) {
                                    entity->addComponent("Heal", new HealAction(playerHealth));
                                }
                            }
                        }
                    }
                }

                if (entity) {
                    add_entity_to_location(location["name"], entity);
                }
            }
        }
    }

    for (const auto& connection : jsonObject["connections"]) {
        add_edge(connection["from"], connection["to"], connection["direction"]);
    }

    Vertex* startingVertex = vertices[startingLocation];
    if (startingVertex) {
        // Set the player's current vertex to the starting vertex.
        currentPlayer->setCurrentLocation(startingVertex);
    }
    else {
        // Handle the case where the starting location is not found in the map.
        std::cerr << "Starting location '" << startingLocation << "' not found in the map." << std::endl;
    }
}



void Map_Graph::add_entity_to_location(const std::string& location_name, Entity* entity) {
    Vertex* v = vertices[location_name];
    if (v) {
        v->entities.push_back(entity);
    }
    else {
        std::cerr << "Location not found: " << location_name << std::endl;
    }
}

void Map_Graph::remove_entity_from_location(const std::string& location_name, const std::string& entity_name) {
    Vertex* v = vertices[location_name];
    if (v) {
        v->entities.erase(std::remove_if(v->entities.begin(), v->entities.end(),
            [&](Entity* ent) { return ent->getName() == entity_name; }), v->entities.end());
    }
    else {
        std::cerr << "Location not found: " << location_name << std::endl;
    }
}

Vertex* Map_Graph::movePlayer(Player* player, const std::string& direction) {
    Vertex* currentLocation = player->getCurrentLocation();

    for (const auto& dir : currentLocation->adj) {
        if (dir.first == direction) {
            return dir.second;
        }
    }
    return nullptr;
}

Map_Graph::Map_Graph()
{
}

Map_Graph::~Map_Graph() {
    for (auto& pair : vertices) {
        delete pair.second;
    }
    vertices.clear();
}
