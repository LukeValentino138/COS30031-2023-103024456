#pragma once
#include "Component.h"
#include <string>

class AttributeComponent : public Component {
public:
    virtual std::string describe() const = 0;
};