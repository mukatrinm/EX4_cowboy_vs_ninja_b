#include "Character.hpp"

#include <stdexcept>

using namespace ariel;

Character::Character(const std::string name, const Point &location, const int hit_points) : name_{name}, current_position_(location), hit_points_{hit_points} {
}

bool Character::isAlive() const {
    return hit_points_ > 0;
}

double Character::distance(const Character *other) const {
    return current_position_.distance(other->getLocation());
}

void Character::hit(int damage) {
    if (damage < 0) {
        throw std::invalid_argument("damage can't be negative.");
    }

    hit_points_ -= damage;
}

std::string Character::getName() const {
    return name_;
}

const Point &Character::getLocation() const {
    return current_position_;
}

void Character::setLocation(const Point location) {
    current_position_ = location;
}

int ariel::Character::getHitPoints() const {
    return hit_points_;
}

void Character::setInTeam() {
    is_in_team_ = true;
}

bool Character::isInTeam() const {
    return is_in_team_;
}
