#pragma once
#include <string>
#include <iostream>
#include "Message.h"
#include <optional>
#include "StateType.h"

class Entity {
private:
    std::string entityID;
    std::string data;
    StateType state;

public:
    Entity(const std::string& id, StateType state = CONTENT);

    void takeMessage(const Message& msg);

    void sendMessage(const std::string& destinationID, MessageType type, StateType state,std::string data);

    std::string getID() const;
    StateType getState() const;
    std::string getData() const;
};
