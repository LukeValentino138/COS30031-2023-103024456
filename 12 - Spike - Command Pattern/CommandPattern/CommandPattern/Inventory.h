#pragma once

#include <map>
#include <string>

class Inventory {
private:
    std::map<std::string, int> items;

public:
    const std::map<std::string, int>& getItems() const;
    void addItem(const std::string& itemName, int quantity = 1);
    bool removeItem(const std::string& itemName, int quantity = 1);
    bool hasItem(const std::string& ItemName) const;
    void printInventory() const;
};
