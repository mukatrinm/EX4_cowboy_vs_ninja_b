#pragma once

#include <string>

#include "Ninja.hpp"

namespace ariel {
class OldNinja : public Ninja {
   public:
    OldNinja(const std::string name, const Point &position);
};
}  // namespace ariel
