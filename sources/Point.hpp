#pragma once

#include <iostream>

namespace ariel {
class Point {
   private:
    double x_coord_, y_coord_;

   public:
    Point(double x_coord, double y_coord);
    Point(const Point &other);
    double distance(const Point &point) const;
    void print() const;
    std::string Point::toString() const;
    static Point moveTowards(const Point &src_pos, const Point &target_pos, double distance);
};
}  // namespace ariel
