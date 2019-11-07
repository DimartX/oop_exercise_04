#pragma once

#include <iostream>
#include <algorithm>

#include "point.hpp"

template<typename number>
class triangle {
    Point<number> pts[3];
    
    triangle(std::istream& in);

    double area() const;
    void print(std::ostream& out) const;
};
