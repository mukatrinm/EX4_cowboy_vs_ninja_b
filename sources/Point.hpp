#pragma once

namespace ariel {
class Point {
   private:
    double x_, y_;

   public:
    Point(double x, double y);
    Point(const Point &other);
    double distance(const Point &point) const;
    void print() const;
    static Point moveTowards(Point &src_pos, Point &target_pos, double distance);
};
}  // namespace ariel
