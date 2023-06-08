#include "Team.hpp"

#include <stdexcept>

using namespace ariel;

Team::Team(Character* leader) {
    add(leader);
}

Team::~Team() {
    for (Character* character : characters_) {
        delete character;
    }

    characters_.clear();
}

void Team::add(Character* character) {
    if (character == nullptr) {
        throw std::invalid_argument("character can't be null.");
    }
    if (character->isInTeam()) {
        throw std::runtime_error("Character is already in a different team\n");
    }

    if (characters_.size() < 10) {
        characters_.push_back(character);
        character->setInTeam();
    } else {
        throw std::runtime_error("Team is full.");
    }
}

void Team::attack(Team* enemy) {
    // TOOD: implement
}

int Team::stillAlive() const {
    int cnt = 0;
    for (const Character* character : characters_) {
        if (character->isAlive()) {
            cnt++;
        }
    }

    return cnt;
}

const std::vector<Character*>& Team::getTeam() const {
    return characters_;
}

void Team::print() const {
    for (Character* character : characters_) {
        character->print();
    }
}