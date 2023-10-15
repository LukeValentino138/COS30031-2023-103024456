#pragma once
#include "Inventory.h"
#include "Vertex.h"

class Player {
private:
	Inventory inventory;
	Vertex* currentLocation;
	int currentScore;
public:
	Inventory getInventory() { return inventory; }

	int getCurrentScore() { return currentScore; }
	void setCurrentScore(int score) { currentScore = score; }

	Vertex* getCurrentLocation() const { return currentLocation; }
	void setCurrentLocation(Vertex* location) { currentLocation = location; }

	Player();
};