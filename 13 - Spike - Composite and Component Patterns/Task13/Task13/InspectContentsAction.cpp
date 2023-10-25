#include "InspectContentsAction.h"

InspectContentsAction::InspectContentsAction(ContainerEntity* containerEntity)
    : container(containerEntity) {}

void InspectContentsAction::execute() {
    auto children = container->getChildren();
    if (children.empty()) {
        std::cout << "The " << container->getName() << " is empty." << std::endl;
    }
    else {
        std::cout << "Inside the " << container->getName() << " you see:" << std::endl;
        for (const auto& child : children) {
            std::cout << "- " << child->getName() << ": " << child->getDescription() << std::endl;
        }
    }
}
