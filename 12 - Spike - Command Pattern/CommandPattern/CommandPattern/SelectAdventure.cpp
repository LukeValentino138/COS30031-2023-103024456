#include "SelectAdventure.h"


StateType SelectAdventure::getStateType() const {
    return StateType::SelectAdventure;
}

void SelectAdventure::update() {
    std::string command;
    std::getline(std::cin, command);  

    if (!_manager) {
        std::cerr << "Error: GameManager instance (_manager) is nullptr!" << std::endl;
        return;
    }

    if (command == "1") {
        std::string mapPath = _manager->getMapFilePath();
        if (!mapPath.empty()) {
            _manager->world.load_map(mapPath);
            _manager->push_state(new Gameplay(_manager));
        }
        else {
            std::cerr << "Error: Map file path is empty!" << std::endl;
        }
    }
    else if (command == "MainMenu") {
        _manager->queuePop(1);
    }
    else {
        std::cerr << "Invalid command: " << command << std::endl;
    }
}


void SelectAdventure::render() {
    std::cout << "Zorkish :: Select Adventure" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "1. Adventure Game" << std::endl;
    std::cout << "Enter 'MainMenu' to return to the Main Menu" << std::endl;
}

SelectAdventure::SelectAdventure(GameManager* manager) {
    _manager = manager;
}
