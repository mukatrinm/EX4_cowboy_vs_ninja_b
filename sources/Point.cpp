#include "Point.hpp"

#include <cmath>
#include <iostream>

using namespace ariel;

Point::Point(double x, double y) : x_{x}, y_{y} {
}

Point::Point(const Point& other) : x_{other.x_}, y_{other.y_} {
}

double Point::distance(const Point& point) const {
    double d_x = x_ - point.x_;
    double d_y = y_ - point.y_;

    return std::sqrt(d_x * d_x + d_y * d_y);
}

void Point::print() const {
    std::cout << "(" << x_ << ", " << y_ << ")" << std::endl;
}

Point Point::moveTowards(Point& src_pos, Point& target_pos, double distance) {
    if (distance < 0) {
        throw std::invalid_argument("Distance must be non-negative.");
    }

    double distance_between_points = src_pos.distance(target_pos);

    // destination point is within reach
    if (distance_between_points <= distance) {
        return Point{target_pos};
    }

    double scaling_factor = distance / distance_between_points;

    // Calculate the vector from source to destination
    double d_x = target_pos.x_ - src_pos.x_;
    double d_y = target_pos.y_ - src_pos.y_;

    return Point{src_pos.x_ + d_x * scaling_factor, src_pos.y_ + d_y * scaling_factor};
}
