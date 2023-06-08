#include "Ninja.hpp"

using namespace ariel;

Ninja::Ninja(const std::string name, const Point& position) : Character(name, position) {
}

void Ninja::SetSpeed(int speed) {
    speed_ = speed;
}

void Ninja::move(Character* enemy) {
}

void Ninja::slash(Character* enemy) {
    if (isAlive() && getLocation().distance(enemy->getLocation()) < 1) {
        enemy->hit(31);
    }
}
