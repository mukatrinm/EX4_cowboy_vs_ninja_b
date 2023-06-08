#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character* leader) {
    characters_.push_back(leader);
}

// Team2::~Team2() {
//     // TODO
// }

void Team2::add(Character* character) {
    if (character != nullptr) {
        if (characters_.size() < 10) {
            characters_.push_back(character);
        } else {
            delete character;  // TODO: make sure i need to really delete the character if the team is full
        }
    }
}

void Team2::attack(Team2* enemy) {
}

int Team2::stillAlive() const {
    int cnt = 0;
    for (Character* character : characters_) {
        if (character->isAlive()) {
            cnt++;
        }
    }

    return cnt;
}

void Team2::print() const {
    for (Character* character : characters_) {
        character->print();
    }
}