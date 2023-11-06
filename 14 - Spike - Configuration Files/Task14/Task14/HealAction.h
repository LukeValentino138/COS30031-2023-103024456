#pragma once

#include "ActionComponent.h"
#include "HealthAttribute.h"

class HealAction : public ActionComponent {
private:
    HealthAttribute* health;
    int healAmount;

public:
    // Constructor with default value for healAmount
    HealAction(HealthAttribute* healthAttr, int amount = 5);

    // Overrides the execute method from ActionComponent
    void execute() override;

    // Overrides the getName method from ActionComponent
    std::string getName() const override { return "Heal"; }
};
