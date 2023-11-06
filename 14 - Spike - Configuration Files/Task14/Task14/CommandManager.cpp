#include "CommandManager.h"
#include "Gameplay.h"
#include <iostream>

CommandManager::CommandManager(Gameplay* gm) : gp(gm) {
    Player* player = gp->getPlayer();
    Map_Graph* world = &(gp->world);

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

    cmds["pickup"] = new CommandPickUp(player, world);
    cmds["grab"] = cmds["pickup"];

    cmds["putdown"] = new CommandPutDown(player, world);
    cmds["drop"] = cmds["putdown"];

    cmds["lookin"] = new CommandLookIn(player);
    cmds["inspect"] = cmds["lookin"];

    cmds["use"] = new CommandUse(player, world);

    cmds["stats"] = new CommandStats(player);


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
