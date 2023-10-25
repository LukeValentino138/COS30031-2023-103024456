#pragma once

#include <unordered_map>
#include <string>
#include "Command.h"
#include "CommandGo.h"
#include "CommandLook.h"
#include "CommandInventory.h"
#include "CommandAlias.h"
#include "CommandDebugTree.h"
#include "CommandHelp.h"
#include "CommandPickUp.h"
#include "CommandPutDown.h"
#include "CommandLookIn.h"
#include "CommandUse.h"
#include "CommandStats.h"

class Gameplay;

class CommandManager {
private:
    std::unordered_map<std::string, Command*> cmds;
    std::unordered_map<std::string, std::string> aliasMap;
    Gameplay* gp;
public:
    CommandManager(Gameplay* gp);
    ~CommandManager();

    void processInput(const std::string& input);
    std::unordered_map<std::string, std::string>& getAliasMap() { return aliasMap; }
};

