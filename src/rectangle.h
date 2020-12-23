#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include "./shape.h"

class Rectangle : public Shape {
public:
    Rectangle(std::string id, double length, double width) : Shape(id) {
        if (length <= 0 || width <= 0) {
            throw std::string("This is not a rectangle!");
        }
        _length = length;
        _width = width;
    }

    Rectangle(std::string id, double length, double width, std::string color) : Shape(id, color) {
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
        return "Rectangle (" + thirdDecimalPlace(_length) + ", " + thirdDecimalPlace(_width) + ")";
    }

    std::string type() const {
        return "Rectangle";
    }

    void accept(Visitor *visitor) {
        visitor->visit(this);
    }

    double length() {
        return _length;
    }

    double width() {
        return _width;
    }

private:
    double _length, _width;

    std::string thirdDecimalPlace(double value) const {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(3) << value;
        return stream.str();
    }
};

#endif