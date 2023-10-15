#pragma once

#include <map>
#include <string>

class Inventory {
private:
    std::map<std::string, int> items;

public:
    void addItem(const std::string& itemName, int quantity = 1);
    bool removeItem(const std::string& itemName, int quantity = 1);
    void printInventory() const;
};
