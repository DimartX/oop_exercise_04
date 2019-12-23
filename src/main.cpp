#include <iostream>
#include <string> 
#include <tuple> 

#include "point.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "rectangle.hpp"

#include "template.hpp"
#include "functions.hpp"


template<class T>
void process(std::ostream& out, T& obj) {
    print(out, obj);
    out << area(obj) << std::endl;
    out << center(obj) << std::endl;
}

void processTuple(std::istream& in, std::ostream& out) {
    std::string objType;
    in >> objType;

    using pii = Point<int>;
    using triangle  = std::tuple<pii, pii, pii>;
    using square    = std::tuple<pii, pii, pii, pii>;
    using rectangle = std::tuple<pii, pii, pii, pii>;

    if (objType == "triangle") {
        triangle obj;
        read(in, obj);
        process<triangle>(out, obj);
    }
    else if (objType == "square") {
        square obj;
        read(in, obj);
        process<square>(out, obj);
    }
    else if (objType == "rectangle") {
        rectangle obj;
        read(in, obj);
        process<rectangle>(out, obj);
    }
    else {
        out << "Wrong object type!" << std::endl;
        return;
    }
}

void processFigure(std::istream& in, std::ostream& out) {
    std::string objType;
    in >> objType;

    using triangle  = Triangle<int>;
    //using square    = Square<int>;
    //using rectangle = Rectangle<int>;
    if (objType == "triangle") {
        triangle obj(in);
        process<triangle>(out, obj);
    }
    // else if (objType == "square") {
    //     Square<int> obj(in);
    //     process<Square<int>>(obj);
    // }
    // else if (objType == "rectangle") {
    //     Rectangle<int> obj(in);
    //     process<Rectangle<int>>(obj);
    //}
    else {
        out << "Wrong object type!" << std::endl;
        return;
    }
}

int main() {
    
    while (std::cin) {
        std::cout << "Enter form(tuple/figure), ";
        std::cout << "figure type(triangle, square, rectangle), " << std::endl; 

        std::string objForm;
        std::cin >> objForm;

        if (objForm == "tuple") {
            processTuple(std::cin, std::cout);
        }
        else if (objForm == "figure") {
            processFigure(std::cin, std::cout);
        }
        else {
            std::cout << "Wrong object form!" << std::endl;
        }
    }
}
