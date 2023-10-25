#pragma once

#include "Command.h"
#include "Player.h"
#include "Map_Graph.h"

class CommandGo : public Command {
private:
    Player* player;
    Map_Graph* map;

public:
    CommandGo(Player* player, Map_Graph* map);
    virtual ~CommandGo();

    void execute() override;

};
