#pragma once

#include <iostream>
#include <string>
#include <vector>

class Entity {
public:
    virtual ~Entity() {}
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
    virtual void addChild(Entity* entity) {}
    virtual void removeChild(Entity* entity) {}
};
