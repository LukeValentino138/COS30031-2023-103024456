#include <stdio.h>
#include <vector>
using namespace std;

#define GRAPH_NODES 7

class Matrix_Graph {
private:
	int adj_matrix[GRAPH_NODES][GRAPH_NODES]{
	{0,0,0,1,0,1,0},
	{0,0,0,1,1,0,0},
	{0,0,0,1,0,0,0},
	{1,1,1,0,0,0,0},
	{0,1,0,0,0,0,1},
	{1,0,0,0,0,0,0},
	{0,0,0,0,1,0,0},
	};

public:
	void print_graph() {
		printf("printing graph adjacency matrix. \n");
		for (int i = 0; i < GRAPH_NODES; i++) {
			for (int j = 0; j < GRAPH_NODES; j++) {
				printf("%d, ", adj_matrix[i][j]);
			}
			printf("\n");
		}
	}

	void print_edges(int node) {
		printf("Node %d edges? ", node);
		for (int j = 0; j < GRAPH_NODES; j++) {
			if (adj_matrix[node - 1][j] == 1) {
				printf("%d, ", j + 1);
			}
			
		}
		printf("\n");
	}
};

class List_Graph {
private:
	vector<int> adj_list[GRAPH_NODES] = {
		{3,5}, // node 1 (index 0) goes to 4 and 6
		{3,4},
		{3},
		{0,1,2},
		{1,6},
		{0},
		{4},
	};
public:
	void print_graph() {
		printf("Printing graph adjacency list.\n");
		for (int i = 0; i < GRAPH_NODES; i++) {
			printf("Node %d", i + 1);
			for (auto n: adj_list[i]) {
				printf(" -> %d ", n + 1);
			}
			printf("\n");
		}
	}

	void print_edges(int node) {
		printf("Printing connections to Node %d: ", node);
		for (int i = 0; i < adj_list[node-1].size(); i++) {
			printf(" -> %d", adj_list[node - 1][i]);
		}
	}

	void add_edge(int a, int b) {
		adj_list[a - 1].push_back(b - 1);
		adj_list[b - 1].push_back(a - 1);
	}

	void erase(vector<int>& v, int key) {
		for (auto it = v.begin(); it != v.end();) {
			if (*it == key) {
				it = v.erase(it);
			}
			else {
				++it;
			}
		}
	}

	void remove_edge(int a, int b) {
		erase(adj_list[a - 1], b - 1);
		erase(adj_list[b - 1], a - 1);
	}

};





