#pragma once
#include <vector>
#include <string>
#include <utility>
#include "Item.h"

struct Vertex {
	typedef std::pair<std::string, Vertex*> ve;
	std::vector<ve> adj;

	std::string name;
	std::string description;
	std::vector<Item> items;

	Vertex(std::string s, std::string desc);
	void print();
};
