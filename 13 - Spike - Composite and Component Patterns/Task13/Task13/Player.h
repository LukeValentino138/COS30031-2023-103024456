#pragma once

#include "Vertex.h"
#include "Inventory.h"

class Player {
private:
    Vertex* currentLocation;
    Inventory inventory;  

public:
    Player() : currentLocation(nullptr) {}

    // Gets the current location of the player.
    inline Vertex* getCurrentLocation() const {
        return currentLocation;
    }

    // Sets the current location of the player.
    inline void setCurrentLocation(Vertex* location) {
        currentLocation = location;
    }

    // Gets a reference to the player's inventory.
    inline Inventory& getInventory() {
        return inventory;
    }
};