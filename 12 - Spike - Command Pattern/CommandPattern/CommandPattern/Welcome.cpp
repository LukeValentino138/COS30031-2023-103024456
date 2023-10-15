#include "Welcome.h"

StateType Welcome::getStateType() const {
    return StateType::Welcome;
}

void Welcome::update() {
    _manager->push_state(new MainMenu(_manager));
}

void Welcome::render() {
    std::cout << "Starting Game..." << std::endl;
}

Welcome::Welcome(GameManager* manager) {
    _manager = manager;
}
