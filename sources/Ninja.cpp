#include "Ninja.hpp"

using namespace ariel;

Ninja::Ninja(const std::string name, const Point& position, const int hit_points) : Character(name, position, hit_points) {
}

void Ninja::SetSpeed(int speed) {
    speed_ = speed;
}

void Ninja::move(Character* enemy) {
    setLocation(Point::moveTowards(getLocation(), enemy->getLocation(), speed_));
}

void Ninja::slash(Character* enemy) {
    if (!isAlive()) {
        throw std::runtime_error("ninja can't slash when he is dead.");
    }
    if (!enemy->isAlive()) {
        throw std::runtime_error("ninja can't slash a dead enemy.");
    }
    if (this == enemy) {
        throw std::runtime_error("ninja can't harm himself.");
    }

    if (getLocation().distance(enemy->getLocation()) < 1) {
        enemy->hit(40);
    }
}

std::string Ninja::print() const {
    std::string ret = "";
    ret += "name: C(" + getName() + ")";
    if (isAlive()) {
        ret += ", hit_points: " + std::to_string(getHitPoints());
    }

    ret += ", current_location: " + getLocation().toString();
    return ret;
}
