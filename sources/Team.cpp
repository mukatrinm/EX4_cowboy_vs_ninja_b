#include "Team.hpp"

#include <stdexcept>

using namespace ariel;

Team::Team(Character* leader) {
    characters_.push_back(leader);
}

// Team::~Team() {
//     // TODO
// }

void Team::add(Character* character) {
    if (character == nullptr) {
        return;
    }

    if (characters_.size() < 10) {
        characters_.push_back(character);
    } else {
        // delete character;  // TODO: make sure i need to really delete the character if the team is full
        throw std::runtime_error("Team is full.");
    }
}

void Team::attack(Team* enemy) {
}

int Team::stillAlive() const {
    // return 0;
    int cnt = 0;
    for (Character* character : characters_) {
        if (character->isAlive()) {
            cnt++;
        }
    }

    return cnt;
}

void Team::print() const {
    for (Character* character : characters_) {
        character->print();
    }
}