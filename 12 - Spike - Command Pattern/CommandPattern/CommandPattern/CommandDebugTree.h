#pragma once

#include "Command.h"
#include "Map_Graph.h"

class CommandDebugTree : public Command {
private:
    Map_Graph* map;
public:
    CommandDebugTree(Map_Graph* map);
    virtual ~CommandDebugTree();

    void execute() override;
};
