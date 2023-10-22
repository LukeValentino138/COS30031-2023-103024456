#include "Vertex.h"

Vertex::Vertex(std::string s, std::string desc) : name(s), description(desc) {}

std::string Vertex::getName()
{
    return name;
}

void Vertex::print() {
    printf("Location [%s]:\n", name.c_str());
    printf("Description: %s\n", description.c_str());

    if (!items.empty()) {
        printf("Items at this location:\n");
        for (const auto& item : items) {
            printf("- %s: %s\n", item.name.c_str(), item.description.c_str());
        }
    }

    printf("Paths:\n");
    for (auto v : adj)
        printf(" %s -> [%s], ", v.first.c_str(), v.second->name.c_str());
    printf("\n-----------------------------\n");
}

bool Vertex::hasItem(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item.name == itemName) {
            return true;
        }
    }
    return false;
}

Item* Vertex::getItemByName(const std::string& itemName) {
    for (auto& item : items) {
        if (item.name == itemName) {
            return &item;
        }
    }
    return nullptr;
}