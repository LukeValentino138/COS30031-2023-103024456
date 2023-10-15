#pragma once
#include <string>

class Item {
public:
	std::string name;
	std::string description;
	Item(const std::string& n, const std::string& desc);
};