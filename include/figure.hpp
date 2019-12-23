#pragma once

#include <iostream>

#include "template.hpp"
#include "point.hpp"

template<typename T, size_t S>
class Figure {
public:
    Figure (std::istream& in) {
        for (int i = 0; i < S; i++) {
            in >> pts[i];
        }
    }
    double area() const;
    Point<double> center() const;
    virtual void print(std::ostream& out) const = 0;
    
    Point<T>& operator[] (size_t id) {
        return pts[id];
    }
    const Point<T>& operator[] (size_t id) const {
        return pts[id];
    }
    
    virtual ~Figure() {};
protected:
    Point<T> pts[S];
};

template<typename T, size_t S>
double Figure<T, S>::area() const {
    double ans = 0;
    for (int i = 1; i < S; i++) {
        ans += crossProd(pts[0], pts[i], pts[i-1]);
    }
    return std::abs(ans) / 2.0;
}


template<typename T, size_t S>
Point<double> Figure<T, S>::center() const {
    Point<double> ans{0, 0};
    for (int i = 1; i < S; i++) {
        ans = ans + pts[i];
    }
    return ans / (double)(S);
}




