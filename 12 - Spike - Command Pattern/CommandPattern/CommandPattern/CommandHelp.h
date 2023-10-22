#pragma once

#include "Command.h"
#include <unordered_map>

class CommandHelp : public Command {
private:
    const std::unordered_map<std::string, Command*>& commands;

public:
    CommandHelp(const std::unordered_map<std::string, Command*>& commandMap);
    virtual ~CommandHelp();

    void execute() override;
};
