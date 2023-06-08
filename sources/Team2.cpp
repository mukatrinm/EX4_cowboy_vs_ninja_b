#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character* leader) : Team(leader) {
}

void Team2::attack(Team* enemy) {
}

void Team2::print() const {
    for (const Character* character : getTeam()) {
        character->print();
    }
}