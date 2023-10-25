#pragma once

#include <iostream>
#include <string>
#include <map>
#include "Component.h"

class Entity {
private:
    std::map<std::string, Component*> components;

public:
    virtual ~Entity();

    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;

    void addComponent(const std::string& key, Component* component);
    Component* getComponent(const std::string& key);
    void removeComponent(const std::string& key);
    void printComponents() const;
    const std::map<std::string, Component*>& getAllComponents() const { return components; }

    virtual void addChild(Entity* entity) {}
    virtual void removeChild(Entity* entity) {}
};
