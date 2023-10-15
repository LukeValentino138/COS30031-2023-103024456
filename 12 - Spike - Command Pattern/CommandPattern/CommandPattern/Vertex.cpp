#include "Vertex.h"
#include <cstdio>

Vertex::Vertex(std::string s, std::string desc) : name(s), description(desc) {}

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
