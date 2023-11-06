#include "HealAction.h"
#include <iostream>

HealAction::HealAction(HealthAttribute* healthAttr, int amount)
    : health(healthAttr), healAmount(amount) {}

void HealAction::execute() {
    if (health) {
        int currentHealth = health->getCurrentHealth();
        health->setCurrentHealth(currentHealth + healAmount);
        std::cout << "Healed for " << healAmount << " points." << std::endl;
    }
}
