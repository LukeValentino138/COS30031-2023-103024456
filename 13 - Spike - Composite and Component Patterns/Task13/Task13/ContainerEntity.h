#pragma once

#include "Entity.h"
#include <vector>

class ContainerEntity : public Entity {
private:
    std::string name;
    std::string description;
    std::vector<Entity*> children;
public:
    ContainerEntity(const std::string& name, const std::string& description);
    std::string getName() const override { return name; }
    std::string getDescription() const override { return description; }
    void printInfo() const;
    const std::vector<Entity*>& getChildren() const;
    void addChild(Entity* entity) override;
    void removeChild(Entity* entity) override;
};
