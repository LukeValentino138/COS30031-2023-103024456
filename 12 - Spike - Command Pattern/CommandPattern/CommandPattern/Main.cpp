#include <iostream>
#include "GameManager.h"
#include "Inventory.h"
#include "Map_Graph.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide the game world filename as a command-line argument." << std::endl;
        return 1;
    } 
    std::string filepath = argv[1];

    GameManager manager(filepath);

    // game loop
    while (manager.running()) {
        manager.current()->render();
        manager.current()->update();
        manager.executePops();
    }
    return 0;
}
