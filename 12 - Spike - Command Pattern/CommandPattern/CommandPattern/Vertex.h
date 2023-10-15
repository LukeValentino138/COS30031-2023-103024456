#pragma once
#include <vector>
#include <string>
#include <utility>

struct Vertex {
	typedef std::pair<std::string, Vertex*> ve;
	std::vector<ve> adj;

	std::string name;
	std::string description;
	Vertex(std::string s, std::string desc);
	void print();
};
