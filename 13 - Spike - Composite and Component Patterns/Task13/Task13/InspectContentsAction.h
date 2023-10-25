#pragma once

#include "ActionComponent.h"
#include "ContainerEntity.h"

class InspectContentsAction : public ActionComponent {
private:
    ContainerEntity* container;

public:
    InspectContentsAction(ContainerEntity* containerEntity);
    void execute() override;
    std::string getName() const override { return "Inspect Contents"; }
};
