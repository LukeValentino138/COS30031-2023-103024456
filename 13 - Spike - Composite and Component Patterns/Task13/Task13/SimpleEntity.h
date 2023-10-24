#pragma once

#include "Entity.h"

class SimpleEntity : public Entity {
private:
    std::string name;
    std::string description;
public:
    SimpleEntity(const std::string& name) : name(name) {}

    std::string getName() const override {return name;}
    std::string getDescription() const override {return description;}
};