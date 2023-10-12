#include <vector>
#include <map>
#include <string>
#include <cstdio>

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
};