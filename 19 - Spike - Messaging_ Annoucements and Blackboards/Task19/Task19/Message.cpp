#include "Message.h"

Message::Message(const std::string& origin, const std::string& dest, MessageType t, const std::string& d)
    : rootID(origin), destinationID(dest), type(t), data(d) {}