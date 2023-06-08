#include "Team.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace ariel;

Team::Team(Character *leader) {
    if (leader == nullptr) {
        throw std::invalid_argument("leader can't be null.");
    }
    if (leader->isInTeam()) {
        throw std::runtime_error("leader is already in a different team\n");
    }

    characters_.push_back(leader);
    leader->setInTeam();
    leader_ = leader;
}

Team::~Team() {
    for (Character *character : characters_) {
        delete character;
    }

    characters_.clear();
}

void Team::add(Character *character) {
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

// bool Team::sortByCharacter(Character *char1, Character *char2) {
//     if (dynamic_cast<Cowboy *>(char1) && dynamic_cast<Ninja *>(char2)) {
//         return true;
//     } else if (dynamic_cast<Ninja *>(char1) && dynamic_cast<Cowboy *>(char2)) {
//         return false;
//     } else {
//         return false;
//     }
// }

// Find closest living character to the leader.
Character *Team::getNearestToLeader() const {
    if (stillAlive() == 0) {
        return nullptr;
    }

    Character *closest_char = nullptr;
    double min_dist = INFINITY;

    for (auto character : characters_) {
        if ((character->isAlive()) && (character != leader_)) {
            double dist = leader_->distance(character);
            if (dist < min_dist) {
                closest_char = character;
                min_dist = dist;
            }
        }
    }
    return closest_char;
}

const Character *ariel::Team::getLeader() const {
    return leader_;
}

void ariel::Team::setLeader(Character *new_leader) {
    leader_ = new_leader;
}

Character *Team::getNearestEnemy(Team *enemy_team) const {
    if (enemy_team->stillAlive() == 0) {
        return nullptr;
    }

    Character *closest_char = nullptr;
    double min_dist = INFINITY;

    for (auto character : enemy_team->getTeam()) {
        if ((character->isAlive()) && (character != leader_)) {
            double dist = leader_->distance(character);
            if (dist < min_dist) {
                closest_char = character;
                min_dist = dist;
            }
        }
    }
    return closest_char;
}

void Team::attack(Team *enemy_team) {
    if (enemy_team == nullptr) {
        throw std::invalid_argument("Enemy team can't be null.");
    }
    if (stillAlive() == 0) {
        throw std::invalid_argument("Team can't attack with no all memebers are dead.");
    }
    if (enemy_team->stillAlive() == 0) {
        throw std::runtime_error("Can't attack a dead team.");
    }
    if (enemy_team == this) {
        throw std::invalid_argument("Team can't self harm.");
    }
    // sort the characters vector by character type
    std::sort(characters_.begin(), characters_.end(), [](Character *a, Character *b) {
        if (dynamic_cast<Cowboy *>(a) && !dynamic_cast<Cowboy *>(b)) {
            return true;
        } else {
            return false;
        }
    });
    // Check if leaders are alive
    if (!(leader_->isAlive())) {
        leader_ = getNearestToLeader();
        std::cout << leader_->print() << std::endl;
        if (!leader_) {
            std::cout << "ooo leader" << std::endl;
            return;
        }
    }
    // Attack enemy with all living members
    Character *enemy_char = getNearestEnemy(enemy_team);
    for (auto character : characters_) {
        if (!enemy_char) {
            return;
        }
        if (!enemy_char->isAlive()) {
            enemy_char = getNearestEnemy(enemy_team);
        }
        if ((enemy_team->stillAlive() == 0) || (stillAlive() == 0)) {
            return;
        }
        if (!character->isAlive()) {
            continue;
        }
        if ((dynamic_cast<Cowboy *>(character) != nullptr) && (dynamic_cast<Cowboy *>(character)->hasboolets())) {
            // shoot enemy if the cowboy has a bullet.
            dynamic_cast<Cowboy *>(character)->shoot(enemy_char);
        } else if (dynamic_cast<Cowboy *>(character) != nullptr) {
            // cowboy without a bullet needs to load
            dynamic_cast<Cowboy *>(character)->reload();
        } else if (dynamic_cast<Ninja *>(character) != nullptr && character->distance(enemy_char) <= 1) {
            // attack if ninja is within 1m range
            dynamic_cast<Ninja *>(character)->slash(enemy_char);
        } else if (dynamic_cast<Ninja *>(character) != nullptr) {
            // get closer to enemy if ninja isn't within 1m range
            dynamic_cast<Ninja *>(character)->move(enemy_char);
        }
    }
}

int Team::stillAlive() const {
    int cnt = 0;
    for (const Character *character : characters_) {
        if (character->isAlive()) {
            cnt++;
        }
    }

    return cnt;
}

const std::vector<Character *> &Team::getTeam() const {
    return characters_;
}

void Team::print() const {
    for (Character *character : characters_) {
        std::cout << character->print() << std::endl;
    }
}