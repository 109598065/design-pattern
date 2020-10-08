#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <math.h>
#include "./shape.h"
#include "./two_dimensional_coordinate.h"

class Triangle : public Shape {
public:
    Triangle(std::string id, std::vector<TwoDimensionalCoordinate *> vectors) : Shape(id) {
        if (vectors.size() != 3) {
            throw std::string("This is not a triangle!");
        }
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

    Triangle(std::string id, std::vector<TwoDimensionalCoordinate *> vectors, std::string color) : Shape(id, color) {
        if (vectors.size() != 3) {
            throw std::string("This is not a triangle!");
        }
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

    double area() const {
        double s = (_side1 + _side2 + _side3) / 2;
        return sqrt(s * (s - _side1) * (s - _side2) * (s - _side3));
    }

    double perimeter() const {
        return _side1 + _side2 + _side3;
    }

    std::string info() const {
        std::string s1 = thirdDecimalPlace(_vectors.at(0)->getX());
        std::string s2 = thirdDecimalPlace(_vectors.at(0)->getY());
        std::string s3 = thirdDecimalPlace(_vectors.at(1)->getX());
        std::string s4 = thirdDecimalPlace(_vectors.at(1)->getY());
        std::string s5 = thirdDecimalPlace(_vectors.at(2)->getX());
        std::string s6 = thirdDecimalPlace(_vectors.at(2)->getY());
        return "Triangle ([" + s1 + ", " + s2 + "], [" + s3 + ", " + s4 + "], [" + s5 + ", " + s6 + "])";
    }

private:
    std::vector<TwoDimensionalCoordinate *> _vectors;
    double _side1, _side2, _side3;

    bool triangleInequality() const {
        if (_side1 + _side2 > _side3 && _side2 + _side3 > _side1 && _side1 + _side3 > _side2)
            return true;
        else
            return false;
    }

    std::string thirdDecimalPlace(double value) const {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(3) << value;
        return stream.str();
    }
};

#endif