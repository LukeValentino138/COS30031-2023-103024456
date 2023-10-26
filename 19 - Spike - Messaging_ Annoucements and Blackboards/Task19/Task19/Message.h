#pragma once
#include <string>

enum MessageType {
    CHANGE_STATE,
    REQUEST_DATA,
};

class Message {
public:
    std::string rootID;
    std::string destinationID;
    MessageType type;
    std::string data;

    Message(const std::string& source, const std::string& dest, MessageType t, const std::string& d);
};