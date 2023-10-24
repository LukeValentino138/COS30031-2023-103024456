#include "ContainerEntity.h"

ContainerEntity::ContainerEntity(const std::string& name, const std::string& description)
    : name(name), description(description) {}

void ContainerEntity::printInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;

    if (!children.empty()) {
        std::cout << "Contains the following entities: " << std::endl;
        for (const auto& child : children) {
            std::cout << "- " << child->getName() << ": " << child->getDescription() << std::endl;
        }
    }
    else {
        std::cout << "This container is empty." << std::endl;
    }
}

const std::vector<Entity*>& ContainerEntity::getChildren() const {
    return children;
}

void ContainerEntity::addChild(Entity* entity) {
    children.push_back(entity);
}

void ContainerEntity::removeChild(Entity* entity) {
    children.erase(std::remove(children.begin(), children.end(), entity), children.end());
}
