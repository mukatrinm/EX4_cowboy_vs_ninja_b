#pragma once

#include <string>

#include "Ninja.hpp"

namespace ariel {
class TrainedNinja : public Ninja {
   public:
    TrainedNinja(std::string name, const Point &position);
};
}  // namespace ariel