#include "TrainedNinja.hpp"

using namespace ariel;

TrainedNinja::TrainedNinja(const std::string name, const Point& position) : Ninja(name, position, 120) {
    SetSpeed(12);
}