#include <iostream>
#include <string> 
#include <tuple> 

#include "point.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "rectangle.hpp"

#include "templates.hpp"

template <class T>
void process() {
    T obj;
    read(std::cin, obj);
    print(std::cout, obj);
    std::cout << area(obj) << std::endl;
    std::cout << center(obj) << std::endl;
}

int main() {
    std::string objType;
    std::cin >> objType;

    if (objType == "tuple") {
        int angles;
        std::cin >> angles;
        if (angles == 3) {
            process<std::tuple<point<int>, point<int>, point<int>>>();
        }
        else if (angles == 4) {
            process<std::tuple<point<int>, point<int>, point<int>, point<int>>>();
        }
        else {
            std::cout << "Wrong points number" << std::endl;
        }
    }
    else if (objType = "type") {
        int angles;
        std::cin >> angles;
        if (angles == 3) {
            process<triangle<int>>();
        }
        else if (angles == 4) {
            process<tetragon<int>>();
        }
        else {
            std::cout << "Wrong points number" << std::endl;
        }
    }
    else {
        std::cout << "Wrong object type!" << std::endl;
    }
}
