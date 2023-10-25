#pragma once
#include "Command.h"
#include "Player.h"
#include "Map_Graph.h"

class CommandPutDown : public Command {
private:
    Player* player;
    Map_Graph* world;

public:
    CommandPutDown(Player* p, Map_Graph* map);
    virtual void execute() override;
};
