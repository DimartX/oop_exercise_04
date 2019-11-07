#pragma once

#include <iostream>

template<class number>
struct Point {
    number x, y;
    Point(number x, number y) : x(x), y(y) {};
    Point() = default;

    Point<number> operator+ (Point<number> const& a, Point<number> const& b) const {
        return Point<number>{a.x + b.x, a.y + b.y};
    }
    Point<number> operator- (Point<number> const& a, Point<number> const& b) const {
        return Point<number>{a.x - b.x, a.y - b.y};
    }
    Point<number> operator* (Point<number> const& a, double const& b) const {
        return Point<number>{a.x * b, a.y * b};
    }
    Point<number> operator/ (Point<number> const& a, double const& b) const {
        return Point<number>{a.x / b, a.y / b};
    }
};

template<class number>
std::istream& operator>> (std::istream& in, Point<number>& pt) {
    is >> pt.x >> pt.y;
    return is;
}
template<class number>
std::ostream& operator<< (std::ostream& out, Point<number> const& pt) {
    out << pt.x << ' ' << pt.y;
    return out;
}
    
