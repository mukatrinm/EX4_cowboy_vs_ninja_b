#include "Cowboy.hpp"

#include "Point.hpp"

using namespace ariel;

Cowboy::Cowboy(const std::string name, const Point& position) : Character(name, position, 110), num_of_bullets_{6} {
}

void Cowboy::shoot(Character* enemy) {
    if (!isAlive()) {
        throw std::runtime_error("cowboy can't shoot when he is dead.");
    }
    if (!enemy->isAlive()) {
        throw std::runtime_error("cowboy can't shoot a dead enemy.");
    }
    if (this == enemy) {
        throw std::runtime_error("cowboy can't harm himself.");
    }

    if (hasboolets()) {
        enemy->hit(10);
        num_of_bullets_--;
    }
}

bool Cowboy::hasboolets() const {
    return num_of_bullets_ > 0;
}

int ariel::Cowboy::NumOfBullets() const {
    return num_of_bullets_;
}

void Cowboy::reload() {
    if (!isAlive()) {
        throw std::runtime_error("can't reload while dead.");
    }

    num_of_bullets_ = 6;
}

std::string Cowboy::print() const {
    std::string ret = "";
    ret += "name: C(" + getName() + ")";
    if (isAlive()) {
        ret += ", hit_points: " + std::to_string(getHitPoints());
    }

    ret += ", current_location: " + getLocation().toString();
    return ret;
}
