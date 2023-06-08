#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character *leader) : Team(leader) {
}

void Team2::attack(Team *enemy_team) {
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
    std::vector<Character *> characters = getTeam();

    // sort the characters vector by character type
    std::sort(characters.begin(), characters.end(), [](Character *a, Character *b) {
        if (dynamic_cast<Cowboy *>(a) && !dynamic_cast<Cowboy *>(b)) {
            return true;
        } else {
            return false;
        }
    });

    // Check if leaders are alive
    if (!(getLeader()->isAlive())) {
        setLeader(getNearestToLeader());

        if (!getLeader()) {
            return;
        }
    }
    // if (!(enemy_team->getLeader()->isAlive())) {
    //     enemy_team->getLeader()->setIsInTeam(false);
    //     enemy_team->setLeader(Nearest_to_leader(enemy_team, enemy_team->getLeader()));
    // }
    // if ((enemy_team->getLeader() == nullptr) || (this->getLeader() == nullptr)) {
    //     return;
    // }

    // Attack enemy with all living members
    Character *enemy_char = getNearestEnemy(enemy_team);
    for (auto character : characters) {
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

void Team2::print() const {
    for (const Character *character : getTeam()) {
        character->print();
    }
}