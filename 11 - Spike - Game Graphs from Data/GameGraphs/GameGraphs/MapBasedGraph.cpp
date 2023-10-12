#include <vector>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

struct Vertex {
	typedef pair<int, Vertex*> ve;
	vector<ve> adj;
	string name;
	Vertex(string s) : name(s) {}
	void print() {
		printf("Vertex [%s]: ", name.c_str());
		for (auto e : adj)
			printf(" -> [%s] (wt=%d), ",
				e.second->name.c_str(),
				e.first);
		printf("\n");
	}
};

class Map_Graph {
public:
	typedef map<string, Vertex*> vmap;
	vmap vertices;
	void add_vertex(const string& name) {
		vmap::iterator itr = vertices.find(name);
		if (itr == vertices.end()) {
			Vertex* v;
			v = new Vertex(name);
			vertices[name] = v;
			return;
		}
		printf("Nope. Vertex [%s] already exist!\n", name.c_str());
	}
	void add_edge(const string& from, const string& to, double cost) {
		Vertex *f = (vertices.find(from)->second);
		Vertex *t = (vertices.find(to)->second);
		pair<int, Vertex*> edge = make_pair(cost, t);
		f->adj.push_back(edge);
	}
	void print() {
		for (auto n : vertices) {
			n.second->print();
		}
	}
};