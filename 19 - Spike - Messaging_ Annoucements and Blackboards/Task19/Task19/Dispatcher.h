#pragma once
#include <vector>
#include "Message.h"
#include "Entity.h"

class Dispatcher {
private:
    static std::vector<Message> pendingMessages;
    static std::vector<Entity*> registeredEntities;

public:
    static void registerEntity(Entity* entity);
    static void unregisterEntity(Entity* entity);
    static void add(const Message& msg);
    static void sendMessage();
};
