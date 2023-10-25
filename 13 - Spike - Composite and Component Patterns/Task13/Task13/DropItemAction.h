#pragma once

#include "ActionComponent.h"
#include "Entity.h"
#include "Map_Graph.h"

class DropItemAction : public ActionComponent {
private:
    Player* player;
    Entity* item;
    Map_Graph* gameWorld;

public:
    DropItemAction(Player* p, Entity* i, Map_Graph* world)
        : player(p), item(i), gameWorld(world) {}

    void execute() override;
    std::string getName() const override {
        return "Drop Item";
    }
};
