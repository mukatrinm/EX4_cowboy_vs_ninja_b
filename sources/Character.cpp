#include "Character.hpp"

#include <stdexcept>

using namespace ariel;

Character::Character(const std::string name, const Point &hit_point) : name_{name}, hit_point_{hit_point} {
}

void Character::setHealth(int health) {
    if (health < 0) {
        throw std::invalid_argument("health can't be negative.");
    }

    health_ = health;
}

bool Character::isAlive() const {
    return health_ > 0;
}

double Character::distance(const Character *other) const {
    return 0.0;
}

void Character::hit(int damage) {
    health_ -= damage;
}

std::string Character::getName() const {
    return name_;
}

Point Character::getLocation() const {
    return hit_point_;
}

void Character::print() const {
}
