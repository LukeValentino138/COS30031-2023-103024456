#pragma once
#include "Command.h"
#include "Player.h"

class CommandLookIn : public Command {
private:
    Player* player;

public:
    CommandLookIn(Player* p);
    virtual void execute() override;
};
