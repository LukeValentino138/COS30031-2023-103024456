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

Vertex::Vertex(std::string s, std::string desc) : name(s), description(desc) {}

std::string Vertex::getName() {
	return name;
}

void Vertex::print() {
    std::cout << "Location: " << name << " - " << description << std::endl;

    // Print adjacent locations
    for (const auto& adjacency : adj) {
        std::cout << "    -> " << adjacency.first << ": " << adjacency.second->name << std::endl;
    }

    // Print entities
    std::cout << "\n    At Location:" << std::endl;
    for (const auto& entity : entities) {
        std::cout << "    - " << entity->getName() << ": ";

        // Check if the entity is a composite and print its contents
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

