#pragma once

#include <iostream>

template<class T>
struct Point {
    T x, y;

    // Если T не числовой тип, останавливать конструктор
    Point(T x, T y) : x(x), y(y) {};
    Point() = default;

    Point<T> operator+ (Point<T> const& a, Point<T> const& b) const {
        return Point<T>{a.x + b.x, a.y + b.y};
    }
    Point<T> operator- (Point<T> const& a, Point<T> const& b) const {
        return Point<T>{a.x - b.x, a.y - b.y};
    }
    Point<T> operator* (Point<T> const& a, double const& b) const {
        return Point<T>{a.x * b, a.y * b};
    }
    Point<T> operator/ (Point<T> const& a, double const& b) const {
        return Point<T>{a.x / b, a.y / b};
    }
};

template<class T>
std::istream& operator>> (std::istream& in, Point<T>& pt) {
    is >> pt.x >> pt.y;
    return is;
}

template<class T>
std::ostream& operator<< (std::ostream& out, Point<T> const& pt) {
    out << pt.x << ' ' << pt.y;
    return out;
}
    
