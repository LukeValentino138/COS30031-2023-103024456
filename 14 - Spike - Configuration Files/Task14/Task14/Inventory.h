#pragma once
#include <string>
#include "Entity.h"
#include "ContainerEntity.h"

class Inventory {
private:
    ContainerEntity itemContainer; 
    int maxItems;

public:
    // Constructor
    Inventory(int maxItems = 10);

    // Add an item to the inventory
    bool addItem(Entity* item);

    // Remove an item from the inventory
    bool removeItem(Entity* item);

    // Check if an item exists in the inventory
    bool hasItem(const std::string& itemName) const;

    // Get an item from the inventory by name
    Entity* getItemByName(const std::string& itemName) const;

    // Get all items in the inventory
    const std::vector<Entity*>& getAllItems() const;

    // Check if the inventory is full
    bool isFull() const;

    // Clear the inventory
    void clear();

    void print() const;
};
