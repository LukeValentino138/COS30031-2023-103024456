#include "CommandDebugTree.h"
#include <iostream>

CommandDebugTree::CommandDebugTree(Map_Graph* map) : map(map) {}

CommandDebugTree::~CommandDebugTree() {}

void CommandDebugTree::execute() {
    if (!map) {
        std::cerr << "Error: Invalid map reference in CommandDebugTree." << std::endl;
        return;
    }
    map->print();
}
