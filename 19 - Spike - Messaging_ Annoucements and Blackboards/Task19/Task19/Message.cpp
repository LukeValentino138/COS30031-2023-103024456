#include "Message.h"

Message::Message(const std::string& rootID, const std::string& dest, MessageType msgType, StateType state, const std::string& data)
    : rootID(rootID), destinationID(dest), type(msgType), state(state), data(data) {}
