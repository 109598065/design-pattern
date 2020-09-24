#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include "./shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double length, double width) {
        if (length <= 0 || width <= 0) {
            throw std::string("This is not a rectangle!");
        }
        _length = length;
        _width = width;
    }

    double area() const {
        return _length * _width;
    }

    double perimeter() const {
        return 2.0 * (_length + _width);
    }

    std::string info() const {
        std::stringstream stream1;
        stream1 << std::fixed << std::setprecision(3) << _length;
        std::string s1 = stream1.str();

        std::stringstream stream2;
        stream2 << std::fixed << std::setprecision(3) << _width;
        std::string s2 = stream2.str();

        return "Rectangle (" + s1 + ", " + s2 + ")";
    }

private:
    double _length, _width;
};

#endif