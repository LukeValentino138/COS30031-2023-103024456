#include "MainMenu.h"
#include "SelectAdventure.h"
#include "HallOfFame.h"
#include "Help.h"
#include "About.h"

StateType MainMenu::getStateType() const {
    return StateType::MainMenu;
}

void MainMenu::update() {
    std::string command;
    std::cin >> command;
    if (command == "1") {
        _manager->push_state(new SelectAdventure(_manager));
    }
    if (command == "2") {
        _manager->push_state(new HallOfFame(_manager));
    }
    if (command == "3") {
        _manager->push_state(new Help(_manager));
    }
    if (command == "4") {
        _manager->push_state(new About(_manager));
    }
    if (command == "5") {
        _manager->queuePop(2);
    }
}

void MainMenu::render() {
    std::cout << "Zorkish :: Main Menu" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Welcome to Zorkish Adventures" << std::endl;
    std::cout << "1. Select Adventure and Play" << std::endl;
    std::cout << "2. Hall of Fame" << std::endl;
    std::cout << "3. Help" << std::endl;
    std::cout << "4. About" << std::endl;
    std::cout << "5. Quit" << std::endl;
    std::cout << "Select 1-5: ";
}

MainMenu::MainMenu(GameManager* manager) {
    _manager = manager;
}
