#pragma once

#include <vector>

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "Point.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
namespace ariel {
class Team {
   private:
    std::vector<Character *> characters_;  // leader must be at index 0.
    Character *leader_ = nullptr;

   public:
    Team(Character *leader);
    Team(Team &team) = delete;
    Team(Team &&team) = delete;
    virtual ~Team();

    void add(Character *character);
    virtual void attack(Team *enemy);
    int stillAlive() const;
    const std::vector<Character *> &getTeam() const;
    virtual void print() const;

    Team &operator=(Team &team) = delete;
    Team &operator=(Team &&team) = delete;
};
}  // namespace ariel
