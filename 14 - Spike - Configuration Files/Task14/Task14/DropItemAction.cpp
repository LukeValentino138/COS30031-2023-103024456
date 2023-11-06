#include "DropItemAction.h"

void DropItemAction::execute() {
    // Check if the item is in the player's inventory
    if (!player->getInventory().hasItem(item->getName())) {
        std::cout << "You don't have " << item->getName() << " in your inventory." << std::endl;
        return;
    }

    // Get the player's current location
    Vertex* playerLocation = player->getCurrentLocation();
    if (playerLocation) {
        // Add the item to the current location in the game world
        gameWorld->add_entity_to_location(playerLocation->getName(), item);

        // Remove the item from the player's inventory
        bool removed = player->getInventory().removeItem(item);
        if (removed) {
            std::cout << "You dropped " << item->getName() << "!" << std::endl;
        }
        else {
            std::cout << "Error: Unable to remove the item from the inventory." << std::endl;
        }
    }
    else {
        std::cout << "Error: Player's location not found." << std::endl;
    }
}
