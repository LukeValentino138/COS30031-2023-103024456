#pragma once

#include "Command.h"
#include "Player.h"

class CommandInventory : public Command {
private:
    Player* player;

public:
    CommandInventory(Player* player);
    virtual ~CommandInventory();

    void execute() override;
};
