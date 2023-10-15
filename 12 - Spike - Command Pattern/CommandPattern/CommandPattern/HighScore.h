#pragma once
#include "State.h"
#include "GameManager.h"
#include "HallOfFame.h"
#include <iostream>

class HighScore : public State {
public:
    StateType getStateType() const override;
    void update() override;
    void render() override;
    explicit HighScore(GameManager* manager);
};
