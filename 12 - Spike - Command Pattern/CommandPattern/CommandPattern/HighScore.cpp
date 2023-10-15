#include "HighScore.h"

StateType HighScore::getStateType() const {
    return StateType::HighScore;
}

void HighScore::update() {
    std::string name;
    std::cin >> name;
    if (!name.empty()) {
        _manager->push_state(new HallOfFame(_manager));
    }
}

void HighScore::render() {
    std::cout << "Zorkish :: New High Score" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Score: 3000" << std::endl;
    std::cout << "Enter your Name:" << std::endl;
}

HighScore::HighScore(GameManager* manager) {
    _manager = manager;
}
