#include "Inventory.h"
#include <iostream>

const std::map<std::string, int>& Inventory::getItems() const
{
    return items;
}

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

bool Inventory::hasItem(const std::string& ItemName) const
{
    return items.find(ItemName) != items.end();
}
