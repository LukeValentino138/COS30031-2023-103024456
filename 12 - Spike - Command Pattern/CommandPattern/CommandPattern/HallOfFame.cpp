#include "HallOfFame.h"

StateType HallOfFame::getStateType() const {
    return StateType::HallOfFame;
}

void HallOfFame::update() {
    std::string command;
    std::cin >> command;
    if (command == "MainMenu") {
        if (_manager->getPreviousState() == StateType::HighScore) {
            _manager->queuePop(4);
        }
        if (_manager->getPreviousState() == StateType::MainMenu) {
            _manager->queuePop(2);
        }
    }
}

void HallOfFame::render() {
    std::cout << "Zorkish :: Hall of Fame" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "High Score List" << std::endl;
    std::cout << "1. Luke: 12000" << std::endl;
    std::cout << "2. George: 11000" << std::endl;
    std::cout << "3. Susan: 10000" << std::endl;
    std::cout << "4. Newman: 9000" << std::endl;
    std::cout << "5. Jerry: 8000" << std::endl;
    std::cout << "6. Elaine: 7000" << std::endl;
    std::cout << "Press Enter to return to the Main Menu" << std::endl;
}

HallOfFame::HallOfFame(GameManager* manager) {
    _manager = manager;
}
