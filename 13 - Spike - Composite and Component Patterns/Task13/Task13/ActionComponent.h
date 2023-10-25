#pragma once
#include "Component.h"
#include <string>

class ActionComponent : public Component {
public:
    virtual ~ActionComponent() = default;
    virtual void execute() = 0;
    virtual std::string getName() const = 0;
};