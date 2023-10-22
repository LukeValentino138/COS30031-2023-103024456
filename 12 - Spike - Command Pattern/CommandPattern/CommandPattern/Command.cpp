#include "Command.h"

Command::Command() : arguments("") {}

Command::~Command() {}

void Command::setArguments(const std::string& args) {
    arguments = args;
}
