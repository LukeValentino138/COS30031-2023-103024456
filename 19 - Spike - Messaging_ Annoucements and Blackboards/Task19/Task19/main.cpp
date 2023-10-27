#include "Entity.h"
#include "Message.h"
#include "Dispatcher.h"
#include "StateType.h"
#include <iostream>

int main() {
    std::cout << "Creating entities..." << std::endl;
    Entity entityA("A", CONTENT);
    Entity entityB("B");

    Dispatcher::registerEntity(&entityA);
    Dispatcher::registerEntity(&entityB);

    std::cout << "Initial states: " << std::endl;
    std::cout << "Entity A state: " << entityA.getState() << std::endl;
    std::cout << "Entity B state: " << entityB.getState() << std::endl;

    std::cout << std::endl << "---Demonstration A, Simple Change State--- " << std::endl;
    std::cout << "Entity A sending CHANGE_STATE message to Entity B:" << std::endl;
    entityA.sendMessage("B", CHANGE_STATE, HAPPY, "");
    Dispatcher::sendMessage();

    std::cout << std::endl << "Current states after CHANGE_STATE message: " << std::endl;
    std::cout << "Entity A state: " << entityA.getState() << std::endl;
    std::cout << "Entity B state: " << entityB.getState() << std::endl;


    std::cout << std::endl << "---Demonstration B, Simple Data Change---" << std::endl;
    std::cout << "Entity A Data: " << entityA.getData() << std::endl;
    std::cout << "Entity B sending data to entity A..." << std::endl;
    entityB.sendMessage("A", SEND_DATA, NOT_SPECIFIED, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    Dispatcher::sendMessage();
    std::cout << "Entity A Data: " << entityA.getData() << std::endl;

    std::cout << std::endl << "---Demonstration C, Simple Data Request---" << std::endl;

    std::cout << "Entity B requesting data from entity A..." << std::endl;
    entityB.sendMessage("A", REQUEST_DATA, NOT_SPECIFIED, "");
    Dispatcher::sendMessage();  // process REQUEST_DATA message
    Dispatcher::sendMessage();  // process the resulting SEND_DATA message

    std::cout << "Entity B Data Recevied from Entity A: " << entityB.getData() << std::endl;




    return 0;
}