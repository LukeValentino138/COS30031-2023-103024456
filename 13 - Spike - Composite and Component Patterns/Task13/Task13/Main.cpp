#include "Map_Graph.h"
#include <iostream>

int main() {
    // Create the map graph
    Map_Graph world;

    // Load map from JSON file
    world.load_map("C:\\Users\\Luke\\Desktop\\task13_map.json");

    // Display the map
    world.print();

    return 0;
}
