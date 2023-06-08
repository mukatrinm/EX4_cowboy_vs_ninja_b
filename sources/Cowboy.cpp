#include "Cowboy.hpp"

using namespace ariel;

Cowboy::Cowboy(const std::string name, Point& position) : Character(name, position) {
    setHealth(110);
}

void Cowboy::shoot(Character* enemy) {
    if (isAlive()) {
        if (hasboolets()) {
            enemy->hit(10);
            num_of_bullets_--;
        }
    }
}

bool Cowboy::hasboolets() const {
    return num_of_bullets_ > 0;
}

void Cowboy::reload() {
    num_of_bullets_ = 6;
}
