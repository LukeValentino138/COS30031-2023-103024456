#pragma once
#include <vector>
#include <string>
#include <utility>
#include <cstdio>
#include "Entity.h"

struct Vertex {
	typedef std::pair<std::string, Vertex*> ve;
	std::vector<ve> adj;

	std::string name;
	std::string description;
	std::vector<Entity*> entities;  // Renamed from items to entities

	Entity* getEntityByName(const std::string& entityName);
	bool hasEntity(const std::string& entityName) const;
	Vertex(std::string s, std::string desc);
	std::string getName();
	void print();

	void addEntity(Entity* entity);
	void removeEntity(const std::string& entityName);

	~Vertex();
};
