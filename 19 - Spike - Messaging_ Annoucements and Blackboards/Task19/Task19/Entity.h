#pragma once
#include <string>
#include <iostream>
#include "Message.h"

class Entity {
private:
    std::string entityID;
    std::string state;

public:
    Entity(const std::string& id, const std::string& initState = "Default");
    void takeMessage(const Message& msg);
    void sendMessage(const std::string& destinationID, MessageType type, const std::string& data);
    std::string getID() const;
    std::string getState() const;
};
