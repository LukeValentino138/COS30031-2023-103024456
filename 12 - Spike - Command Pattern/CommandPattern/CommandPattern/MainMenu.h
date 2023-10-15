#pragma once
#include "State.h"
#include "GameManager.h"
#include <iostream>

class MainMenu : public State {
public:
    StateType getStateType() const override;
    void update() override;
    void render() override;
    explicit MainMenu(GameManager* manager);
};
