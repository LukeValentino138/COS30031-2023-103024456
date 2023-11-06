#pragma once

#include "Command.h"
#include "Player.h"

class CommandStats : public Command {
private:
    Player* player;

public:
    CommandStats(Player* p);
    virtual void execute() override;
};
