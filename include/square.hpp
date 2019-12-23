#pragma once

#include <iostream>
#include <algorithm>

#include "point.hpp"
#include "template.hpp"
#include "figure.hpp"

template<class T>
class Square : Figure<T, 4> {
public:
    Square() = default;
    Square(std::istream& in) : Figure<T, 4>(in) {
        int a = dist(Figure<T, 4>::pts[0], Figure<T, 4>::pts[1]);
        bool is_Square = true;
        for (int i = 0; i < 4; i++) {
            if (dist(Figure<T, 4>::pts[i], Figure<T, 4>::pts[(i + 1) % 4]) != a ||
                scalarProd(Figure<T, 4>::pts[i], Figure<T, 4>::pts[(i + 1) % 4], Figure<T, 4>::pts[(i + 2) % 4] != 0)) {
                is_Square = false;
            }
        }
        if (is_Square == false) {
            std::cout << "GO FUCK" << std::endl;
            ~Square();
        }
    };

    void print(std::ostream& out) const override {
        out << "Square: " << std::endl;
        for (int i = 0; i < 4; i++) {
            out << Figure<T, 4>::pts[i] << std::endl;
        }
    }
    ~Square() {};
};
