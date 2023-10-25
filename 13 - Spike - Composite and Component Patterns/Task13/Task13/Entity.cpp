#include "Entity.h"

Entity::~Entity() {
    for (auto& pair : components) {
        delete pair.second;
    }
}

void Entity::addComponent(const std::string& key, Component* component) {
    if (components.find(key) != components.end()) {
        delete components[key];
    }
    components[key] = component;
}

Component* Entity::getComponent(const std::string& key) {
    if (components.find(key) != components.end()) {
        return components[key];
    }
    return nullptr;
}

void Entity::removeComponent(const std::string& key) {
    if (components.find(key) != components.end()) {
        delete components[key];
        components.erase(key);
    }
}

// Inside Entity.h or Entity.cpp
void Entity::printComponents() const {
    if (components.empty()) {
        std::cout << "No components." << std::endl;
        return;
    }
    for (const auto& pair : components) {
        std::cout << "    Component: " << pair.first << " -> Type: " << typeid(*pair.second).name() << std::endl;
    }
}
