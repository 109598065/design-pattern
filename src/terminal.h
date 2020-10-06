#ifndef TERMINAL_H
#define TERMINAL_H

#include <regex>
#include "./rectangle.h"
#include "./ellipse.h"
#include "./triangle.h"
#include "./sort.h"

class Terminal {
public:
    Terminal(std::string input) {
        std::string doubleString = "[+-]?\\d*\\.?\\d+";
        std::regex regexRectangle("Rectangle +\\( *" + doubleString + " *, *" + doubleString +
                                  " *\\)\\s+");
        std::regex regexEllipse("Ellipse +\\( *" + doubleString + " *, *" + doubleString +
                                " *\\)\\s+");
        std::regex regexTriangle(
                "Triangle +\\( *\\[ *" + doubleString + " *, *" + doubleString + " *\\] *, *\\[ *" + doubleString +
                "*, *" + doubleString + " *\\] *, *\\[ *" + doubleString + " *, *" + doubleString + " *\\] *\\)\\s+");

        shapeSearch(input, regexRectangle, 0);
        shapeSearch(input, regexEllipse, 1);
        shapeSearch(input, regexTriangle, 2);

        std::smatch m;
        bool isMatch = false;
        if (std::regex_search(input, m, std::regex("(area|perimeter) (inc|dec)")))
            isMatch = true;

        if (_shapes.empty() || !isMatch) {
            throw std::string("invalid input");
        }

        if (std::regex_search(input, m, std::regex("area"))) {
            _isArea = true;
        }
        if (std::regex_search(input, m, std::regex("inc"))) {
            _isIncrement = true;
        }

        if (_isArea && _isIncrement)
            quickSort(_shapes.begin(), _shapes.end(), areaAscendingCompare);
        else if (_isArea && !_isIncrement)
            quickSort(_shapes.begin(), _shapes.end(), areaDescendingCompare);
        else if (!_isArea && _isIncrement)
            quickSort(_shapes.begin(), _shapes.end(), perimeterAscendingCompare);
        else
            quickSort(_shapes.begin(), _shapes.end(), perimeterDescendingCompare);
    }

    std::string showResult() {
        std::string result = "";

        for (int i = 0; i < _shapes.size(); i++) {
            std::stringstream stream;
            stream << std::fixed << std::setprecision(3) << (_isArea ? _shapes.at(i)->area() : _shapes.at(
                    i)->perimeter());
            std::string s = stream.str();

            result += s;
            result += i != _shapes.size() - 1 ? "\n" : "";
        }
        return result;
    }

private:
    std::vector<Shape *> _shapes;
    std::string _feature, _order;
    bool _isArea = false, _isIncrement = false;

    void shapeSearch(std::string input, std::regex regex, int shapeType) {
        std::smatch m;

        while (std::regex_search(input, m, regex)) {
            for (auto x:m) {

                std::string z = x.str();
                std::smatch m2;
                double a, b, c, d, e, f;
                if (shapeType == 0 || shapeType == 1) {
                    std::regex_search(z, m2, std::regex("[+-]?\\d*\\.?\\d+"));
                    a = std::atof(m2.str().data());
                    z = m2.suffix().str();

                    std::regex_search(z, m2, std::regex("[+-]?\\d*\\.?\\d+"));
                    b = std::atof(m2.str().data());
                    z = m2.suffix().str();
                } else {
                    std::regex_search(z, m2, std::regex("[+-]?\\d*\\.?\\d+"));
                    a = std::atof(m2.str().data());
                    z = m2.suffix().str();

                    std::regex_search(z, m2, std::regex("[+-]?\\d*\\.?\\d+"));
                    b = std::atof(m2.str().data());
                    z = m2.suffix().str();

                    std::regex_search(z, m2, std::regex("[+-]?\\d*\\.?\\d+"));
                    c = std::atof(m2.str().data());
                    z = m2.suffix().str();

                    std::regex_search(z, m2, std::regex("[+-]?\\d*\\.?\\d+"));
                    d = std::atof(m2.str().data());
                    z = m2.suffix().str();

                    std::regex_search(z, m2, std::regex("[+-]?\\d*\\.?\\d+"));
                    e = std::atof(m2.str().data());
                    z = m2.suffix().str();

                    std::regex_search(z, m2, std::regex("[+-]?\\d*\\.?\\d+"));
                    f = std::atof(m2.str().data());
                    z = m2.suffix().str();
                }

                try {
                    Shape *shape;
                    if (shapeType == 0)
                        shape = new Rectangle(a, b);
                    else if (shapeType == 1)
                        shape = new Ellipse(a, b);
                    else {
                        std::vector<TwoDimensionalCoordinate *> triangleVector;
                        triangleVector.push_back(new TwoDimensionalCoordinate(a, b));
                        triangleVector.push_back(new TwoDimensionalCoordinate(c, d));
                        triangleVector.push_back(new TwoDimensionalCoordinate(e, f));
                        shape = new Triangle(triangleVector);
                    }

                    _shapes.push_back(shape);
                } catch (std::string e) {
                }
            }
            input = m.suffix().str();
        }
    }
};

#endif
