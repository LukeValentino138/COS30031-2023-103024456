#pragma once
#include <string>

class Item {
public:
	std::string name;
	std::string description;
	Item(const std::string& n, const std::string& desc);
	std::pair<std::string, std::string> getItem(const std::string& itemName) const;
	Item() : name(""), description("") {};
};