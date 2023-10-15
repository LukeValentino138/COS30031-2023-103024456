#include "Map_Graph.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

void Map_Graph::add_vertex(const std::string& name, const std::string& description) {
    vmap::iterator itr = vertices.find(name);
    if (itr == vertices.end()) {
        Vertex* v;
        v = new Vertex(name, description);
        vertices[name] = v;
        return;
    }
    printf("Nope. Vertex [%s] already exist!\n", name.c_str());
}

void Map_Graph::add_edge(const std::string& from, const std::string& to, const std::string& direction) {
    Vertex* f = (vertices.find(from)->second);
    Vertex* t = (vertices.find(to)->second);
    std::pair<std::string, Vertex*> edge = std::make_pair(direction, t);
    f->adj.push_back(edge);
}

void Map_Graph::print() {
    for (auto n : vertices) {
        n.second->print();
    }
}

void Map_Graph::load_map(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error, cannot open file: " << filename << std::endl;
        return;
    }

    nlohmann::json jsonObject;
    file >> jsonObject;

    for (const auto& location : jsonObject["locations"]) {
        add_vertex(location["name"], location["description"]);
    }

    for (const auto& connection : jsonObject["connections"]) {
        add_edge(connection["from"], connection["to"], connection["direction"]);
    }
}
