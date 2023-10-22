#include "Item.h"

Item::Item(const std::string& n, const std::string& desc)
    : name(n), description(desc) {}

std::pair<std::string, std::string> Item::getItem(const std::string& itemName) const
{
    return std::pair<std::string, std::string>();
}
