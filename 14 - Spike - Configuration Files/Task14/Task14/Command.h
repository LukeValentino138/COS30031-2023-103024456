#pragma once

#include <string>

class Command {
protected:
    std::string arguments;
public:
    Command();
    virtual ~Command();

    virtual void execute() = 0;

    virtual void setArguments(const std::string& args);


};
