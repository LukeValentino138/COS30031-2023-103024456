#include "HealthAttribute.h"

HealthAttribute::HealthAttribute(int initialHealth)
    : currentHealth(initialHealth) {}

void HealthAttribute::setCurrentHealth(int value) {
    currentHealth = value;

    // Ensure health doesn't go below zero
    if (currentHealth < 0) {
        currentHealth = 0;
    }
}

int HealthAttribute::getCurrentHealth() const {
    return currentHealth;
}

std::string HealthAttribute::describe() const {
    return std::to_string(currentHealth);
}
