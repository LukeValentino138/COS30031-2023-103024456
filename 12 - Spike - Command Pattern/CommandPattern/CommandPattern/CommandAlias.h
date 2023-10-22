#pragma once

#include "Command.h"
#include <unordered_map>

class CommandAlias : public Command {
private:
    std::unordered_map<std::string, std::string>& aliases;
public:
    CommandAlias(std::unordered_map<std::string, std::string>& aliasMap);
    virtual ~CommandAlias();

    void execute() override;
};
