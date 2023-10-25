#pragma once

#include "Command.h"
#include "Player.h"
#include "Map_Graph.h"

class CommandLook : public Command {
private:
    Player* player;
    Map_Graph* map;
public:
    CommandLook(Player* player, Map_Graph* map);
    virtual ~CommandLook();

    void execute() override;


};
