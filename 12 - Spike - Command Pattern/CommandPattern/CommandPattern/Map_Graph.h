#pragma once
#include <map>
#include <string>
#include "Vertex.h"
#include "Player.h"

class Map_Graph {
public:
    typedef std::map<std::string, Vertex*> vmap;
    vmap vertices;

    void add_vertex(const std::string& name, const std::string& description);
    void add_edge(const std::string& from, const std::string& to, const std::string& direction);
    void print();
    void load_map(const std::string& filename);
    void add_item_to_location(const std::string& location_name, const Item& item);
    void remove_item_from_location(const std::string& location_name, const std::string& item_name);
    Vertex* movePlayer(Player* player, const std::string& direction);
};
