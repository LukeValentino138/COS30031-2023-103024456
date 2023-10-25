#pragma once

#include "AttributeComponent.h"

class HealthAttribute : public AttributeComponent {
private:
    int currentHealth;

public:
    HealthAttribute(int initialHealth);

    // Setter
    void setCurrentHealth(int value);

    // Getter
    int getCurrentHealth() const;

    std::string describe() const override;
};
