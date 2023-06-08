#pragma once

#include <string>

#include "Point.hpp"

namespace ariel {
class Character {
   private:
    const std::string name_;
    Point current_position_;
    int hit_points_;
    bool is_in_team_ = false;

   public:
    Character(const std::string name, const Point &location, const int hit_points);
    Character(const Character &other) = delete;
    Character(Character &&other) = delete;
    virtual ~Character() = default;

    Character &operator=(Character &other) = delete;
    Character &operator=(Character &&other) = delete;

    bool isAlive() const;
    double distance(const Character *other) const;
    void hit(int damage);
    std::string getName() const;
    const Point &getLocation() const;
    int getHitPoints() const;
    virtual std::string print() const = 0;
    void setInTeam();
    bool isInTeam() const;
};
}  // namespace ariel
