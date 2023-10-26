#include "Entity.h"
#include "Dispatcher.h"

Entity::Entity(const std::string& id, const std::string& initState) : entityID(id), state(initState) {}

void Entity::takeMessage(const Message& msg) {
    if (msg.type == CHANGE_STATE) {
        state = msg.data;
        std::cout << "Entity " << entityID << " changed state to: " << state << std::endl;
    }
    else if (msg.type == REQUEST_DATA) {
        std::string responseData = "Response from " + entityID + " to " + msg.rootID;
        sendMessage(msg.rootID, CHANGE_STATE, responseData);
    }
}

void Entity::sendMessage(const std::string& destinationID, MessageType type, const std::string& data) {
    Message msg(this->entityID, destinationID, type, data);
    Dispatcher::add(msg);
}

std::string Entity::getID() const {
    return entityID;
}

std::string Entity::getState() const {
    return state;
}
