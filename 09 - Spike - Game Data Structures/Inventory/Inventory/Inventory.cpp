#include <iostream>
#include <map>
using namespace std;

class Inventory {
private:
    map<string, int> items;

public:
    void addItem(const string& itemName, int quantity = 1) {
        items[itemName] += quantity;
    }

    bool removeItem(const string& itemName, int quantity = 1) {
        auto it = items.find(itemName);

        it->second -= quantity;

        if (it->second <= 0) {
            items.erase(it);
        }
        return true;
    }

    void printInventory() const {
        for (const auto& pair : items) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    Inventory playerInventory;

    playerInventory.addItem("Sword", 1);
    playerInventory.addItem("Bread", 2);

    std::cout << "Initial Inventory:" << std::endl;
    playerInventory.printInventory();

    std::cout << "\nInventory after removing a sword and bread:" << std::endl;

    playerInventory.removeItem("Sword", 1);
    playerInventory.removeItem("Bread", 1);

    playerInventory.printInventory();

    std::cout << "\nInventory after removing a more bread:" << std::endl;
    playerInventory.removeItem("Bread", 10);

    playerInventory.printInventory();


    return 0;
}
