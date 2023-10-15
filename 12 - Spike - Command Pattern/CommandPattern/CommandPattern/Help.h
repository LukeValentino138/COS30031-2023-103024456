#pragma once
#include "State.h"
#include "GameManager.h"
#include <iostream>

class Help : public State {
public:
    StateType getStateType() const override;
    void update() override;
    void render() override;
    explicit Help(GameManager* manager);
};
