#include "TrainedNinja.hpp"

using namespace ariel;

TrainedNinja::TrainedNinja(const std::string name, const Point& position) : Ninja(name, position) {
    setHealth(120);
    SetSpeed(12);
}