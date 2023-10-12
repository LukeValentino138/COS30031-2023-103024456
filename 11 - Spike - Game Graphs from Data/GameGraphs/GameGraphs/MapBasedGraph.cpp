#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <json.hpp>

using namespace std;

struct Vertex {
	typedef pair<string, Vertex*> ve;
	vector<ve> adj;

	string name;
	string description;
	Vertex(string s, string desc) : name(s), description(desc) {}

	void print() {
		printf("Vertex [%s]: ", name.c_str());
		for (auto v : adj)
			printf(" %s -> [%s], ", v.first.c_str(), v.second->name.c_str());
		printf("\n");
	}
};


class Map_Graph {
public:
	typedef map<string, Vertex*> vmap;
	vmap vertices;

	void add_vertex(const string& name, const string& description) {
		vmap::iterator itr = vertices.find(name);
		if (itr == vertices.end()) {
			Vertex* v;
			v = new Vertex(name, description);
			vertices[name] = v;
			return;
		}
		printf("Nope. Vertex [%s] already exist!\n", name.c_str());
	}

	void add_edge(const string& from, const string& to, const string& direction) {
		Vertex* f = (vertices.find(from)->second);
		Vertex* t = (vertices.find(to)->second);
		pair<string, Vertex*> edge = make_pair(direction, t);
		f->adj.push_back(edge);
	}

	void print() {
		for (auto n : vertices) {
			n.second->print();
		}
	}

	void load_map(const string& filename) {
		ifstream file(filename);

		if (!file.is_open()) {
			cerr << "Error, cannot open file: " << filename << endl;
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
};

class Gameplay {
public:
	string currentLocation = "Bus Depot";
	string command;

	void start_game(Map_Graph& graph) {
		while (true) {
			cout << "You are at: " << currentLocation << endl;
			cout << "Available directions: ";
			for (const auto& dir : graph.vertices[currentLocation]->adj) {
				cout << dir.first << " ";
			}
			cout << endl;

			cout << "Enter command (go [direction] or quit): ";
			cin >> command;

			if (command == "quit") {
				break;
			}
			else if (command == "go") {
				string direction;
				cin >> direction;

				bool found = false;
				for (const auto& dir : graph.vertices[currentLocation]->adj) {
					if (dir.first == direction) {
						currentLocation = dir.second->name;
						found = true;
						break;
					}
				}
				if (!found) {
					cout << "Invalid direction!" << endl;
				}
			}
			else {
				cout << "Invalid command!" << endl;
			}
		}
	}
};

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cerr << "Please provide the game world filename as a command-line argument." << endl;
		return 1;
	}

	string filepath = argv[1];

	Map_Graph graph;

	graph.load_map(filepath); 

	graph.print();

	Gameplay gm;

	gm.start_game(graph);
}
