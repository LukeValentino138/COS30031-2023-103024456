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

    playerInventory.printInventory();

    return 0;
}
