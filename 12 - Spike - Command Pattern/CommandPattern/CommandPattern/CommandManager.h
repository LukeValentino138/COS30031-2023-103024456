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
#include "GameManager.h"

class CommandManager {
private:
    std::unordered_map<std::string, Command*> cmds;
    std::unordered_map<std::string, std::string> aliasMap;
    GameManager* gameManager;
public:
    CommandManager(GameManager* gm);
    ~CommandManager();

    void processInput(const std::string& input);
    std::unordered_map<std::string, std::string>& getAliasMap() { return aliasMap; }
};
