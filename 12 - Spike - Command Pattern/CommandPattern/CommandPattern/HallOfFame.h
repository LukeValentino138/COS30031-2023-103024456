#pragma once
#include "State.h"
#include "GameManager.h"
#include <iostream>

class HallOfFame : public State {
public:
    StateType getStateType() const override;
    void update() override;
    void render() override;
    explicit HallOfFame(GameManager* manager);
};
