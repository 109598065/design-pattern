#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <math.h>
#include <stdexcept>
#include "./shape.h"

class Ellipse : public Shape {
public:
    Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes) : Shape(id) {
        if (semiMajorAxes <= 0 || semiMinorAxes <= 0 || semiMajorAxes < semiMinorAxes) {
            throw std::string("This is not an ellipse!");
        }
        _semiMajorAxes = semiMajorAxes;
        _semiMinorAxes = semiMinorAxes;
    }

    Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes, std::string color) : Shape(id, color) {
        if (semiMajorAxes <= 0 || semiMinorAxes <= 0 || semiMajorAxes < semiMinorAxes) {
            throw std::string("This is not an ellipse!");
        }
        _semiMajorAxes = semiMajorAxes;
        _semiMinorAxes = semiMinorAxes;
    }

    double area() const {
        return M_PI * _semiMajorAxes * _semiMinorAxes;
    }

    double perimeter() const {
        return 2 * M_PI * _semiMinorAxes + 4 * (_semiMajorAxes - _semiMinorAxes);
    }

    std::string info() const {
        return "Ellipse (" + thirdDecimalPlace(_semiMajorAxes) + ", " + thirdDecimalPlace(_semiMinorAxes) + ")";
    }

    std::string type() const {
        return "Ellipse";
    }

    void accept(Visitor *visitor) {
        visitor->visit(this);
    }

    double semiMajorAxes() {
        return _semiMajorAxes;
    }

    double semiMinorAxes() {
        return _semiMinorAxes;
    }

private:
    double _semiMajorAxes, _semiMinorAxes;

    std::string thirdDecimalPlace(double value) const {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(3) << value;
        return stream.str();
    }
};

#endif