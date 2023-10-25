#include "Inventory.h"
#include <iostream>

// Constructor
Inventory::Inventory(int maxItems)
    : itemContainer("Inventory", "Player's Inventory"),
    maxItems(maxItems) {}

bool Inventory::addItem(Entity* item) {
    if (!isFull()) {
        itemContainer.addChild(item);
        return true;
    }
    return false;
}

bool Inventory::removeItem(Entity* item) {
    itemContainer.removeChild(item);
    return true; 
}

bool Inventory::hasItem(const std::string& itemName) const {
    for (const auto& child : itemContainer.getChildren()) {
        if (child->getName() == itemName) {
            return true;
        }
    }
    return false;
}

Entity* Inventory::getItemByName(const std::string& itemName) const {
    for (const auto& child : itemContainer.getChildren()) {
        if (child->getName() == itemName) {
            return child;
        }
    }
    return nullptr;
}

const std::vector<Entity*>& Inventory::getAllItems() const {
    return itemContainer.getChildren();
}

bool Inventory::isFull() const {
    return itemContainer.getChildren().size() >= maxItems;
}

void Inventory::clear() {
    for (const auto& child : itemContainer.getChildren()) {
        itemContainer.removeChild(child);
    }
}

void Inventory::print() const {
    if (itemContainer.getChildren().empty()) {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    std::cout << "Inventory contents:" << std::endl;
    for (const auto& item : itemContainer.getChildren()) {
        std::cout << "- " << item->getName() << std::endl;
    }
}
