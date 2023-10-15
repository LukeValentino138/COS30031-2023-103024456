#pragma once
#include "State.h"
#include "GameManager.h"
#include "MainMenu.h"
#include <iostream>

class Welcome : public State {
public:
    StateType getStateType() const override;
    void update() override;
    void render() override;
    explicit Welcome(GameManager* manager);
};
#pragma once
