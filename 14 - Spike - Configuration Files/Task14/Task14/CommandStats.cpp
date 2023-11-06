#include "CommandStats.h"
#include <iostream>

CommandStats::CommandStats(Player* p) : player(p) {}

void CommandStats::execute() {
    if (!player) {
        std::cerr << "Error: Invalid player reference in CommandStats." << std::endl;
        return;
    }

    player->printComponents();
}
