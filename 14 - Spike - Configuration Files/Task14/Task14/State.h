#pragma once
#include "StateType.h"

class GameManager;

class State {
protected:
    GameManager* _manager = nullptr;
public:

    virtual StateType getStateType() const = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};
