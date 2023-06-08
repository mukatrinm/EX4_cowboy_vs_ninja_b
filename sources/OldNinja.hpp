#pragma once

#include <string>

#include "Ninja.hpp"

namespace ariel {
class OldNinja : public Ninja {
   public:
    OldNinja(std::string name, const Point &position);
};
}  // namespace ariel
