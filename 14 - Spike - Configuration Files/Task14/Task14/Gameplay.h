#pragma once
#include "State.h"
#include "GameManager.h"
#include <iostream>
#include "Map_Graph.h"

class CommandManager;

class Gameplay : public State {
private:
    CommandManager* cmdManager;
    GameManager* _manager;    
    Player player;
    std::string mapFilePath;

public:
    std::string currentLocation = "Bus Depot"; //hardcoded, will change later
    Map_Graph world;

    Gameplay(GameManager* manager, const std::string& filepath);
    ~Gameplay();
    StateType getStateType() const override;

    Player* getPlayer() { return &player; }
    std::string getMapFilePath() const;

    void update() override;
    void render() override;
};
