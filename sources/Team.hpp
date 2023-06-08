#pragma once

#include <vector>

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "Point.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

// TODO: add copy and assignment constructors
namespace ariel {
class Team {
   private:
    std::vector<Character *> characters_;  // leader must be at index 0.
    Character *leader_ = nullptr;

   public:
    Team(Character *leader);
    // ~Team();
    void add(Character *character);
    void attack(Team *enemy);
    int stillAlive() const;
    void print() const;
};
}  // namespace ariel
