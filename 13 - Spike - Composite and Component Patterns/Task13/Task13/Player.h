#pragma once

#include "Entity.h"
#include "Vertex.h"
#include "Inventory.h"
#include "AttributeComponent.h"

class Player : public Entity {
private:
    Vertex* currentLocation;
    Inventory inventory;

public:
    Player() : currentLocation(nullptr) {}

    
    std::string getName() const override {
        return "Player";
    }

    std::string getDescription() const override {
        return "The main character of the game.";
    }

    Vertex* getCurrentLocation() const {
        return currentLocation;
    }

    void setCurrentLocation(Vertex* location) {
        currentLocation = location;
    }

    Inventory& getInventory() {
        return inventory;
    }

    void printComponents() const;
};
