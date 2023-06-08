#pragma once

#include "Character.hpp"

namespace ariel {
class Ninja : public Character {
   private:
    int speed_ = 0;

   protected:
    void SetSpeed(int speed);

   public:
    Ninja(std::string name, const Point &position, int hit_points);
    void move(Character *enemy);
    void slash(Character *enemy);
    std::string print() const override;
};
}  // namespace ariel
