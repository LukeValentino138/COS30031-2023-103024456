#pragma once
#include <string>
#include "StateType.h"

enum MessageType {
    CHANGE_STATE,
    SEND_DATA,
    REQUEST_DATA,
};

class Message {
public:
    std::string rootID;
    std::string destinationID;
    MessageType type;
    StateType state;
    std::string data;

    Message(const std::string& rootID, const std::string& dest, MessageType msgType, StateType state, const std::string& data = "");
};