#include "Dispatcher.h"
#include <algorithm>

std::vector<Message> Dispatcher::pendingMessages;
std::vector<Entity*> Dispatcher::registeredEntities;

void Dispatcher::registerEntity(Entity* entity) {
    registeredEntities.push_back(entity);
}

void Dispatcher::unregisterEntity(Entity* entity) {
    registeredEntities.erase(std::remove(registeredEntities.begin(), registeredEntities.end(), entity), registeredEntities.end());
}

void Dispatcher::add(const Message& msg) {
    pendingMessages.push_back(msg);
}

void Dispatcher::sendMessage() {
    std::vector<Message> localMessages = pendingMessages; // Copy pending messages to a local list
    pendingMessages.clear(); // Clear the global list

    for (const Message& msg : localMessages) {
        for (Entity* entity : registeredEntities) {
            if (entity->getID() == msg.destinationID) {
                entity->takeMessage(msg);
            }
        }
    }
}

