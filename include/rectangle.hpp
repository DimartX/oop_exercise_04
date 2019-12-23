#pragma once

#include <iostream>
#include <algorithm>

#include "point.hpp"
#include "template.hpp"

template<typename T>
class Rectangle : Figure<T, 4> {
public:
    Rectangle() = default;
    Rectangle(std::istream& in) : Figure<T, 4>(in) {
        int a = dist(Figure<T, 4>::pts[0], Figure<T, 4>::pts[1]);
        bool is_Rectangle = (dist(Figure<T, 4>::pts[0], Figure<T, 4>::pts[1]) == dist(Figure<T, 4>::pts[2], Figure<T, 4>::pts[3]) &&
                             dist(Figure<T, 4>::pts[0], Figure<T, 4>::pts[3]) == dist(Figure<T, 4>::pts[1], Figure<T, 4>::pts[2]));
        for (int i = 0; i < 4; i++) {
            if (scalarProd(Figure<T, 4>::pts[i], Figure<T, 4>::pts[(i + 1) % 4], Figure<T, 4>::pts[(i + 2) % 4] != 0)) {
                is_Rectangle = false;
            }
        }
        if (is_Rectangle == false) {
            std::cout << "GO FUCK" << std::endl;
            ~Rectangle();
        }
    };

    void print(std::ostream& out) const override {
        out << "Rectangle: " << std::endl;
        for (int i = 0; i < 4; i++) {
            out << Figure<T, 4>::pts[i] << std::endl;
        }
    }
    ~Rectangle() {};
};
