#ifndef TRIANGLE
#define TRIANGLE

#include <math.h>
#include "shape.h"
#include "two_dimensional_coordinate.h"

class Triangle : public Shape {
public:
    Triangle(std::vector<TwoDimensionalCoordinate *> vectors) {
        _side1 = sqrt(pow(vectors.at(0)->getX() - vectors.at(1)->getX(), 2)
                      + pow(vectors.at(0)->getY() - vectors.at(1)->getY(), 2));
        _side2 = sqrt(pow(vectors.at(1)->getX() - vectors.at(2)->getX(), 2)
                      + pow(vectors.at(1)->getY() - vectors.at(2)->getY(), 2));
        _side3 = sqrt(pow(vectors.at(0)->getX() - vectors.at(2)->getX(), 2)
                      + pow(vectors.at(0)->getY() - vectors.at(2)->getY(), 2));
        if (!triangleInequality()) {
            throw std::string("This is not a triangle!");
        }
        _vectors = vectors;
    }

    bool triangleInequality() {
        if (_side1 + _side2 > _side3 && _side2 + _side3 > _side1 && _side1 + _side3 > _side2)
            return true;
        else
            return false;
    }

    double area() const {
        double s = (_side1 + _side2 + _side3) / 2;
        return sqrt(s * (s - _side1) * (s - _side2) * (s - _side3));
    }

    double perimeter() const {
        return _side1 + _side2 + _side3;
    }

    std::string info() const {
        std::stringstream stream1;
        stream1 << std::fixed << std::setprecision(3) << _vectors.at(0)->getX();
        std::string s1 = stream1.str();

        std::stringstream stream2;
        stream2 << std::fixed << std::setprecision(3) << _vectors.at(0)->getY();
        std::string s2 = stream2.str();

        std::stringstream stream3;
        stream3 << std::fixed << std::setprecision(3) << _vectors.at(1)->getX();
        std::string s3 = stream3.str();

        std::stringstream stream4;
        stream4 << std::fixed << std::setprecision(3) << _vectors.at(1)->getY();
        std::string s4 = stream4.str();

        std::stringstream stream5;
        stream5 << std::fixed << std::setprecision(3) << _vectors.at(2)->getX();
        std::string s5 = stream5.str();

        std::stringstream stream6;
        stream6 << std::fixed << std::setprecision(3) << _vectors.at(2)->getY();
        std::string s6 = stream6.str();

        return "Triangle ([" + s1 + ", " + s2 + "], [" + s3 + ", " + s4 + "], [" + s5 + ", " + s6 + "])";
    }

private:
    std::vector<TwoDimensionalCoordinate *> _vectors;
    double _side1, _side2, _side3;
};

#endif