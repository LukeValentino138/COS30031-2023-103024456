#include "SelectAdventure.h"
#include "Map_Graph.h"

StateType SelectAdventure::getStateType() const {
    return StateType::SelectAdventure;
}

void SelectAdventure::update() {
    std::string command;
    std::cin >> command;
    if (command == "1") {
        std::string mapFilePath = _manager->getMapFilePath();
        _manager->push_state(new Gameplay(_manager, mapFilePath));
    }
    if (command == "MainMenu") {
        _manager->queuePop(1);
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
