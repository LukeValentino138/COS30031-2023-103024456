#pragma once
#include <stack>
#include "State.h"
#include "StateType.h"
#include <string>

class GameManager {
private:
    std::stack<State*> _states; // LIFO
    std::string mapFilePath;
    StateType _previousState = StateType::None;
    int _numPopsRequired = 0;
public:
    std::string getMapFilePath() const;  // getter declaration
    bool running() const;
    State* current();
    StateType getPreviousState() const;
    void queuePop(int num);
    void executePops();
    void push_state(State* state);
    void pop_state();
    ~GameManager();
    GameManager(const std::string& filepath);  // constructor declaration
};
