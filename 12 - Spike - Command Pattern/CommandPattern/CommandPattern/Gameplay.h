#pragma once
#include "State.h"
#include "GameManager.h"
#include "HighScore.h"
#include <iostream>
#include "Map_Graph.h"

class Gameplay : public State {
private:
    std::string currentLocation = "Bus Depot";
    Map_Graph graph;

public:
    Gameplay(GameManager* manager, const std::string& mapFilePath);
    StateType getStateType() const override;
    void update() override;
    void render() override;
};