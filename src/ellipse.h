#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <math.h>
#include <stdexcept>
#include "./shape.h"

class Ellipse : public Shape {
public:
    Ellipse(double semiMajorAxes, double semiMinorAxes) {
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
        std::stringstream stream1;
        stream1 << std::fixed << std::setprecision(3) << _semiMajorAxes;
        std::string s1 = stream1.str();

        std::stringstream stream2;
        stream2 << std::fixed << std::setprecision(3) << _semiMinorAxes;
        std::string s2 = stream2.str();

        return "Ellipse (" + s1 + ", " + s2 + ")";
    }

private:
    double _semiMajorAxes, _semiMinorAxes;
};

#endif