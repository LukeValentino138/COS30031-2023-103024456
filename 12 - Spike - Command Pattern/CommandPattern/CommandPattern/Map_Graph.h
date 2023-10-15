#pragma once
#include <map>
#include <string>
#include "Vertex.h"

class Map_Graph {
public:
    typedef std::map<std::string, Vertex*> vmap;
    vmap vertices;

    void add_vertex(const std::string& name, const std::string& description);
    void add_edge(const std::string& from, const std::string& to, const std::string& direction);
    void print();
    void load_map(const std::string& filename);
};
