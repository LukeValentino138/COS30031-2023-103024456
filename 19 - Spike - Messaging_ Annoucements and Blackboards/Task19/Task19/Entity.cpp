#include "Entity.h"
#include "Dispatcher.h"

Entity::Entity(const std::string& id, StateType state) : entityID(id), state(state) {}

void Entity::takeMessage(const Message& msg) {
    if (msg.type == CHANGE_STATE) {
        state = msg.state;
    }
    else if (msg.type == SEND_DATA) {
        data = msg.data;
    }
    else if (msg.type == REQUEST_DATA) {
        sendMessage(msg.rootID, SEND_DATA, NOT_SPECIFIED, this->data);
    }
}

void Entity::sendMessage(const std::string& destinationID, MessageType type, StateType state, std::string data)
{
    Message msg(this->entityID, destinationID, type, state, data);
    Dispatcher::add(msg);
}

std::string Entity::getID() const {
    return entityID;
}

StateType Entity::getState() const {
    return state;
}

std::string Entity::getData() const
{
    return data;
}
