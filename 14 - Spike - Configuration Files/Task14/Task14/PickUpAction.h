#pragma once

#include "ActionComponent.h"
#include "Entity.h"
#include "Map_Graph.h"

class PickUpAction : public ActionComponent {
private:
    Player* player;
    Entity* item;
    Map_Graph* gameWorld;

public:
    PickUpAction(Player* p, Entity* i, Map_Graph* world)
        : player(p), item(i), gameWorld(world) {}

    void execute() override;
    std::string getName() const override {
        return "Pick Up";
    }
};
