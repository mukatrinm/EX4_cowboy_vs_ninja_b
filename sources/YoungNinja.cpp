#include "YoungNinja.hpp"

using namespace ariel;

YoungNinja::YoungNinja(const std::string name, const Point& position) : Ninja(name, position, 100) {
    SetSpeed(14);
}