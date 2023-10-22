#include "CommandManager.h"
#include <iostream>

CommandManager::CommandManager(GameManager* gm) : gameManager(gm) {
    Player* player = gameManager->getPlayer();
    Map_Graph* world = &(gameManager->world);

    // Move
    cmds["move"] = new CommandGo(player, world);
    cmds["go"] = cmds["move"];

    // Look
    cmds["look"] = new CommandLook(player, world);
    cmds["look at"] = new CommandLook(player, world);

    // Inventory
    cmds["inventory"] = new CommandInventory(player);
    cmds["inv"] = cmds["inventory"];

    // Alias 
    cmds["alias"] = new CommandAlias(aliasMap);

    // Debug
    cmds["debug"] = new CommandDebugTree(world);

    //Help
    cmds["help"] = new CommandHelp(cmds);

}


CommandManager::~CommandManager() {
    for (auto& pair : cmds) {
        delete pair.second;
    }
}

void CommandManager::processInput(const std::string& input) {
    std::string command = input.substr(0, input.find(' '));
    std::string args = (input.find(' ') != std::string::npos) ? input.substr(input.find(' ') + 1) : "";

    if (aliasMap.find(command) != aliasMap.end()) {
        command = aliasMap[command];
    }

    if (cmds.find(command) != cmds.end()) {
        cmds[command]->setArguments(args);
        cmds[command]->execute();
    }
    else {
        std::cout << "Unknown command: " << command << std::endl;
    }
}
