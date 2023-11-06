#include "PickUpAction.h"

void PickUpAction::execute() {
    if (!player || !item) {
        std::cerr << "Error: Invalid reference in PickUpAction." << std::endl;
        return;
    }

    // Check if the player's inventory is full
    if (player->getInventory().isFull()) {
        std::cout << "Your inventory is full. Cannot pick up the item." << std::endl;
        return;
    }

    // Check if the item is in the same location as the player
    Vertex* playerLocation = player->getCurrentLocation();
    if (playerLocation && playerLocation->hasEntity(item->getName())) {

        // Remove the item from the current location
        playerLocation->removeEntity(item->getName());

        // Add the item to the player's inventory
        bool added = player->getInventory().addItem(item);
        if (added) {
            std::cout << "You picked up " << item->getName() << "!" << std::endl;
        }
        else {
            std::cout << "Error: Unable to add the item to the inventory." << std::endl;
        }
    }
    else {
        std::cout << "The item is not present at your current location." << std::endl;
    }
}
