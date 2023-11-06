#pragma once
#include <stack>
#include "State.h"
#include "StateType.h"
#include "Map_Graph.h"
#include "Player.h"
#include <string>

class GameManager {
private:
    std::stack<State*> _states; // LIFO

    StateType _previousState = StateType::None;
    int _numPopsRequired = 0; 
public:


    bool running() const;
    State* current();
    StateType getPreviousState() const;
    void queuePop(int num);
    void executePops();
    void push_state(State* state);
    void pop_state();


    ~GameManager();
    GameManager(const std::string& filepath);;
};
