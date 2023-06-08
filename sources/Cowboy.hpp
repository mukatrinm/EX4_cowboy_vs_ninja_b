#pragma once

#include "Character.hpp"

namespace ariel {
class Cowboy : public Character {
   private:
    int num_of_bullets_ = 6;

   public:
    Cowboy(const std::string name, Point &position);
    void shoot(Character *enemy);
    bool hasboolets() const;
    void reload();
};
}  // namespace ariel