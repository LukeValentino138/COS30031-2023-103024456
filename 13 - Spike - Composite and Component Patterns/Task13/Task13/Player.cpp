#include "Player.h"

void Player::printComponents() const {
    for (const auto& pair : this->getAllComponents()) {
        const std::string& key = pair.first;
        Component* comp = pair.second;

        AttributeComponent* attrComp = dynamic_cast<AttributeComponent*>(comp);
        if (attrComp) {
            std::cout << key << ": " << attrComp->describe() << std::endl;
        }
        else {
            std::cout << key << ": (Not an attribute component)" << std::endl;
        }
    }
}
