#pragma once
#include "State.h"
#include "GameManager.h"
#include "HighScore.h"
#include <iostream>
#include "Map_Graph.h"
#include "CommandManager.h"  

class Gameplay : public State {
private:
    CommandManager cmdManager;  
    GameManager* _manager;      

public:
    Gameplay(GameManager* manager);
    StateType getStateType() const override;
    void update() override;
    void render() override;
};
