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
    int NumOfBullets() const;
    void reload();
    std::string print() const override;
};
}  // namespace ariel