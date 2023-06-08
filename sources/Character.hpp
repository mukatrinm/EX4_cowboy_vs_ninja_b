#pragma once

#include <string>

#include "Point.hpp"

namespace ariel {
class Character {
   private:
    const std::string name_;
    int health_ = 0;
    Point hit_point_;

   protected:
    void setHealth(int health);

   public:
    Character(const std::string name, const Point &hit_point);
    bool isAlive() const;
    double distance(const Character *other) const;
    void hit(int damage);
    std::string getName() const;
    Point getLocation() const;
    void print() const;
};
}  // namespace ariel
