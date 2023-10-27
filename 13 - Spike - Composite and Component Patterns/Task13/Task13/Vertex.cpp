#include "Vertex.h"
#include "ContainerEntity.h"

Entity* Vertex::getEntityByName(const std::string& entityName) {
    for (auto& entity : entities) {
        if (entity->getName() == entityName) {
            return entity;
        }
    }
    return nullptr;
}

bool Vertex::hasEntity(const std::string& entityName) const {
    for (const auto& entity : entities) {
        if (entity->getName() == entityName) {
            return true;
        }
    }
    return false;
}

void Vertex::removeEntity(const std::string& entityName) {
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        if ((*it)->getName() == entityName) {
            entities.erase(it);
            break;
        }
    }
}

void Vertex::addEntity(Entity* entity) {
    entities.push_back(entity);
}

std::string Vertex::getName() {
	return name;
}

void Vertex::print() {
    std::cout << "Location: " << name << " - " << description << std::endl;

    for (const auto& adjacency : adj) {
        std::cout << "    -> " << adjacency.first << ": " << adjacency.second->name << std::endl;
    }

    std::cout << "\n    At Location:" << std::endl;
    for (const auto& entity : entities) {
        std::cout << "    - " << entity->getName() << ": ";

        ContainerEntity* compositeEntity = dynamic_cast<ContainerEntity*>(entity);
        if (compositeEntity) {
            std::cout << std::endl;
            for (const auto& childEntity : compositeEntity->getChildren()) {
                std::cout << "        - " << childEntity->getName() << ": " << childEntity->getDescription() << std::endl;
                
            }
        }
        else {
            std::cout << entity->getDescription() << std::endl;
        }
    }
}
Vertex::Vertex(std::string s, std::string desc) : name(s), description(desc) {}

Vertex::~Vertex() {
    for (Entity* entity : entities) {
        delete entity;
    }
    entities.clear();
}


