#include "Vertex.h"
#include <cstdio>

Vertex::Vertex(std::string s, std::string desc) : name(s), description(desc) {}

void Vertex::print() {
    printf("Vertex [%s]: ", name.c_str());
    for (auto v : adj)
        printf(" %s -> [%s], ", v.first.c_str(), v.second->name.c_str());
    printf("\n");
}
