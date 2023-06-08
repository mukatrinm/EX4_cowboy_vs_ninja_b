#include "Point.hpp"

#include <cmath>
#include <iostream>

using namespace ariel;

Point::Point(double x_coord, double y_coord) : x_coord_{x_coord}, y_coord_{y_coord} {
}

Point::Point(const Point& other) : x_coord_{other.x_coord_}, y_coord_{other.y_coord_} {
}

double Point::distance(const Point& point) const {
    double d_x = x_coord_ - point.x_coord_;
    double d_y = y_coord_ - point.y_coord_;

    return std::sqrt(d_x * d_x + d_y * d_y);
}

void Point::print() const {
    std::cout << "(" << x_coord_ << ", " << y_coord_ << ")" << std::endl;
}

std::string Point::toString() const {
    return "(" + std::to_string(x_coord_) + ", " + std::to_string(y_coord_) + ")";
}

Point Point::moveTowards(const Point& src_pos, const Point& target_pos, double distance) {
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
    double d_x = target_pos.x_coord_ - src_pos.x_coord_;
    double d_y = target_pos.y_coord_ - src_pos.y_coord_;

    return Point{src_pos.x_coord_ + d_x * scaling_factor, src_pos.y_coord_ + d_y * scaling_factor};
}
