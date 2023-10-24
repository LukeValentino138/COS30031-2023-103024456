#pragma once
#include <map>
#include <string>
#include "Vertex.h"
#include "Player.h"
#include "Entity.h" // Including Entity header

class Map_Graph {
public:
    typedef std::map<std::string, Vertex*> vmap;
    vmap vertices;

    void add_vertex(const std::string& name, const std::string& description);
    void add_edge(const std::string& from, const std::string& to, const std::string& direction);
    void print();
    void load_map(const std::string& filename);

    // Updated function names and parameter types
    void add_entity_to_location(const std::string& location_name, Entity* entity);
    void remove_entity_from_location(const std::string& location_name, const std::string& entity_name);

    Vertex* movePlayer(Player* player, const std::string& direction);
};