#pragma once
#include <stack>
#include "State.h"
#include "StateType.h"
#include <string>
#include "Map_Graph.h"
#include "Player.h"

class GameManager {
private:
    std::stack<State*> _states; // LIFO
    std::string mapFilePath;
    StateType _previousState = StateType::None;
    int _numPopsRequired = 0; 
    Player player;

public:
    std::string currentLocation = "Bus Depot"; //hardcoded, will change later
    Map_Graph world;
    std::string getMapFilePath() const; 

    Player* getPlayer() { return &player; }

    void loadMap(const std::string& filepath);

    bool running() const;
    State* current();
    StateType getPreviousState() const;
    void queuePop(int num);
    void executePops();
    void push_state(State* state);
    void pop_state();


    ~GameManager();
    GameManager(const std::string& filepath);
};
