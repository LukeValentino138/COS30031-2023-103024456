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
    for (const Message& msg : pendingMessages) {
        for (Entity* entity : registeredEntities) {
            if (entity->getID() == msg.destinationID) {
                entity->takeMessage(msg);
            }
        }
    }
    pendingMessages.clear();
}