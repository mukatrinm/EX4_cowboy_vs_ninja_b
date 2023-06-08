#include "OldNinja.hpp"

#include <string>

using namespace ariel;

OldNinja::OldNinja(const std::string name, const Point& position) : Ninja(name, position) {
    setHealth(150);
    SetSpeed(8);
}