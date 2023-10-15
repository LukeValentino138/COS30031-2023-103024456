#include "About.h"

StateType About::getStateType() const {
    return StateType::About;
}

void About::update() {
    std::string command;
    std::cin >> command;
    if (command == "MainMenu") {
        _manager->pop_state();
    }
}

void About::render() {
    std::cout << "Zorkish :: About" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Written By: Luke Valentino" << std::endl;
    std::cout << "Student Number: 103024456" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
}

About::About(GameManager* manager) {
    _manager = manager;
}