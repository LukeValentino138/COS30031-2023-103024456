#include "Inventory.h"
#include <iostream>

void Inventory::addItem(const std::string& itemName, int quantity) {
    items[itemName] += quantity;
}

bool Inventory::removeItem(const std::string& itemName, int quantity) {
    auto it = items.find(itemName);
    if (it != items.end()) {
        it->second -= quantity;
        if (it->second <= 0) {
            items.erase(it);
        }
        return true;
    }
    return false;  
}

void Inventory::printInventory() const {
    for (const auto& pair : items) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}
