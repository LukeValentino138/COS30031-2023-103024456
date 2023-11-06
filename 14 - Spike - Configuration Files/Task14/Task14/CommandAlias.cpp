#include "CommandAlias.h"
#include <iostream>
#include <sstream>
#include <vector>

CommandAlias::CommandAlias(std::unordered_map<std::string, std::string>& aliasMap)
    : aliases(aliasMap) {}

CommandAlias::~CommandAlias() {}

void CommandAlias::execute() {
    std::stringstream ss(arguments);
    std::string originalCmd, aliasCmd;
    ss >> originalCmd >> aliasCmd;

    if (originalCmd.empty() || aliasCmd.empty()) {
        std::cout << "Invalid alias command. Use: ALIAS [original command] [alias command]" << std::endl;
        return;
    }

    aliases[aliasCmd] = originalCmd;  // aliasCmd maps to originalCmd
    std::cout << "Command '" << originalCmd << "' has been aliased to '" << aliasCmd << "'." << std::endl;
}
