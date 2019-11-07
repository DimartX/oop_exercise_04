#pragma once

#include <iostream>

#include "point.hpp"

template<typename T>
class Square {
    Square(Point<T> a,...) : Figure<T>(Point<T> a,...) {
        // Если кол-во передаваемых аргументов не равно 4,
        // останавливать конструктор

        // Если получается не квадрат, останавливать

        // Если всё ок, завершать конструкцию
    }
    
private:
    Point<T> pts[4];
};
