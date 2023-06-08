#pragma once

#include <vector>

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "Point.hpp"
#include "Team.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

namespace ariel {
class Team2 : public Team {
   public:
    Team2(Character *leader);
    void attack(Team *enemy_team) override;
    void print() const override;
};
}  // namespace ariel
