#include "GameManager.h"
#include "Welcome.h"

std::string GameManager::getMapFilePath() const {
    return mapFilePath;
}

bool GameManager::running() const {
    return !_states.empty();
}

State* GameManager::current() {
    return _states.top();
}

StateType GameManager::getPreviousState() const {
    return _previousState;
}

void GameManager::queuePop(int num) {
    _numPopsRequired = num;
}

void GameManager::executePops() {
    for (int i = 0; i < _numPopsRequired; i++) {
        if (!_states.empty()) {
            pop_state();
        }
    }
    _numPopsRequired = 0;  // Reset counter
}

void GameManager::push_state(State* state) {
    if (!_states.empty()) {
        _previousState = _states.top()->getStateType();
    }
    _states.push(state);
}

void GameManager::pop_state() {
    _previousState = _states.top()->getStateType();
    delete _states.top();
    _states.pop();
}

GameManager::~GameManager() {
    while (!_states.empty()) pop_state();
}

GameManager::GameManager(const std::string& filepath) : mapFilePath(filepath) {
    //add a first state to be ready
    push_state(new Welcome(this));
}
