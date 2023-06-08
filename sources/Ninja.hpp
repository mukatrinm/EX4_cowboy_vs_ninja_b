#pragma once

#include "Character.hpp"

namespace ariel {
class Ninja : public Character {
   private:
    int speed_ = 0;

   protected:
    void SetSpeed(int speed);

   public:
    Ninja(const std::string name, const Point &position);
    void move(Character *enemy);
    void slash(Character *enemy);
};
}  // namespace ariel
