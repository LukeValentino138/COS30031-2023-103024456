#pragma once
#include "State.h"
#include "GameManager.h"
#include "Gameplay.h"
#include <iostream>

class SelectAdventure : public State {
public:
    StateType getStateType() const override;
    void update() override;
    void render() override;
    explicit SelectAdventure(GameManager* manager);
};
#pragma once
