#include "Help.h"

StateType Help::getStateType() const {
    return StateType::Help;
}

void Help::update() {
    std::string command;
    std::cin >> command;
    if (command == "MainMenu") {
        _manager->pop_state();
    }
}

void Help::render() {
    std::cout << "Zorkish :: Help" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "quit," << std::endl;
    std::cout << "hiscore" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
}

Help::Help(GameManager* manager) {
    _manager = manager;
}
