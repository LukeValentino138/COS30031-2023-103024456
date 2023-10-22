#pragma once
#include <vector>
#include <string>
#include <utility>
#include <cstdio>
#include "Item.h"
#include "Vertex.h"
#include "Inventory.h"

struct Vertex {
	typedef std::pair<std::string, Vertex*> ve;
	std::vector<ve> adj;

	std::string name;
	std::string description;
	std::vector<Item> items;

	Item* getItemByName(const std::string& itemName);
	bool hasItem(const std::string& itemName) const;
	Vertex(std::string s, std::string desc);
	std::string getName();
	void print();
};
