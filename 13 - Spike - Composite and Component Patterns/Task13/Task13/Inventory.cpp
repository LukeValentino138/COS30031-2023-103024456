#include "Inventory.h"

Inventory::Inventory(int maxItems) : maxItems(maxItems) {}

bool Inventory::addItem(Entity* item) {
    if (items.size() < maxItems) {
        items.push_back(item);
        return true;
    }
    return false;
}

bool Inventory::removeItem(Entity* item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
        return true;
    }
    return false;
}

bool Inventory::hasItem(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item->getName() == itemName) {
            return true;
        }
    }
    return false;
}

Entity* Inventory::getItemByName(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

const std::vector<Entity*>& Inventory::getAllItems() const {
    return items;
}

bool Inventory::isFull() const {
    return items.size() >= maxItems;
}

void Inventory::clear() {
    items.clear();
}
