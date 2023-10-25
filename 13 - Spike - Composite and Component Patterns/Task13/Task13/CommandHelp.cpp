#include "CommandHelp.h"
#include <iostream>

CommandHelp::CommandHelp(const std::unordered_map<std::string, Command*>& commandMap)
    : commands(commandMap) {}

CommandHelp::~CommandHelp() {}

void CommandHelp::execute() {
    std::cout << "Available commands:" << std::endl;
    for (const auto& pair : commands) {
        std::cout << "- " << pair.first << std::endl;
    }
}
