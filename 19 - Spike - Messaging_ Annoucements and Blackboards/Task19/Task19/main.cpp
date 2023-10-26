#include "Entity.h"
#include "Message.h"
#include "Dispatcher.h"
#include <iostream>

int main() {
    std::cout << "Creating entities..." << std::endl;
    Entity entityA("A", "Idle");
    Entity entityB("B", "Idle");

    Dispatcher::registerEntity(&entityA);
    Dispatcher::registerEntity(&entityB);

    std::cout << "Initial states: " << std::endl;
    std::cout << "Entity A state: " << entityA.getState() << std::endl;
    std::cout << "Entity B state: " << entityB.getState() << std::endl;

    std::cout << std::endl << "Entity A sending CHANGE_STATE message to Entity B..." << std::endl;
    entityA.sendMessage("B", CHANGE_STATE, "Working");
    Dispatcher::sendMessage();

    std::cout << std::endl << "Current states after CHANGE_STATE message: " << std::endl;
    std::cout << "Entity A state: " << entityA.getState() << std::endl;
    std::cout << "Entity B state: " << entityB.getState() << std::endl;

    std::cout << std::endl << "Entity B requesting state of Entity A..." << std::endl;
    entityB.sendMessage("A", REQUEST_DATA, "");
    Dispatcher::sendMessage();

    std::cout << "Entity A requesting state of Entity B..." << std::endl;
    entityA.sendMessage("B", REQUEST_DATA, "");
    Dispatcher::sendMessage();
    std::cout << "Entity A state after receiving response from B: " << entityA.getState() << std::endl;

    std::cout << std::endl << "Unregistering Entity B..." << std::endl;
    Dispatcher::unregisterEntity(&entityB);
    std::cout << "Entity A sending CHANGE_STATE message to Entity B..." << std::endl;
    entityA.sendMessage("B", CHANGE_STATE, "Resting");
    Dispatcher::sendMessage();

    std::cout << std::endl << "Final states (Entity B should remain unchanged): " << std::endl;
    std::cout << "Entity A state: " << entityA.getState() << std::endl;
    std::cout << "Entity B state: " << entityB.getState() << std::endl;

    return 0;
}