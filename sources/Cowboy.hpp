#pragma once

#include "Character.hpp"

namespace ariel {
class Cowboy : public Character {
   private:
    int num_of_bullets_;

   public:
    Cowboy(std::string name, const Point &position);
    void shoot(Character *enemy);
    bool hasboolets() const;
    int NumOfBullets() const;
    void reload();
    std::string print() const override;
};
}  // namespace ariel