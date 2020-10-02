#ifndef TERMINAL_H
#define TERMINAL_H

#include <regex>

class Terminal {
public:
    Terminal(std::string input) {
        input.erase(0, input.find_first_not_of(" "));
        input.erase(input.find_last_not_of(" ") + 1);

        std::string temp = input;
        std::string temp1 = get_last_word(temp);
        temp.erase(temp.find_last_of(" "));
        std::string temp2 = get_last_word(temp);

        std::smatch m;
        std::string doubleString = "[+-]?\\d*\\.?\\d+";
        std::regex regexRectangle("Rectangle +\\( *" + doubleString + " *, *" + doubleString +
                                  " *\\) +");
        std::regex regexEllipse("Ellipse +\\( *" + doubleString + " *, *" + doubleString +
                                " *\\) +");
        std::regex regexTriangle(
                "Triangle +\\( *\\[ *" + doubleString + " *, *" + doubleString + " *\\] *, *\\[ *" + doubleString +
                "*, *" + doubleString + " *\\] *, *\\[ *" + doubleString + " *, *" + doubleString + " *\\] *\\) +");

        shapeSearch(input, regexRectangle, 0);
        shapeSearch(input, regexEllipse, 1);
        shapeSearch(input, regexTriangle, 2);

        bool isMatch = false;
        if ((temp2 == "area" || temp2 == "perimeter") && (temp1 == "inc" || temp1 == "dec"))
            isMatch = true;


        if (_vectors.empty() || !isMatch) {
            throw std::string("invalid input");
        }

        if (std::regex_search(input, m, std::regex("area"))) {
            isArea = true;
        }
        if (std::regex_search(input, m, std::regex("inc"))) {
            isIncrement = true;
        }

        if (isArea && isIncrement)
            quickSort(_vectors.begin(), _vectors.end(), areaAscendingCompare);
        else if (isArea && !isIncrement)
            quickSort(_vectors.begin(), _vectors.end(), areaDescendingCompare);
        else if (!isArea && isIncrement)
            quickSort(_vectors.begin(), _vectors.end(), perimeterAscendingCompare);
        else
            quickSort(_vectors.begin(), _vectors.end(), perimeterDescendingCompare);
    }

    std::string showResult() {
        std::string result = "";

        for (int i = 0; i < _vectors.size(); i++) {
            std::stringstream stream;
            stream << std::fixed << std::setprecision(3) << (isArea ? _vectors.at(i)->area() : _vectors.at(
                    i)->perimeter());
            std::string s = stream.str();

            result += s;
            result += i != _vectors.size() - 1 ? "\n" : "";
        }
        return result;
    }

private:
    std::vector<Shape *> _vectors;
    bool isArea = false, isIncrement = false;

    void shapeSearch(std::string input, std::regex regex, int shape) {
        std::smatch m;

        while (std::regex_search(input, m, regex)) {
            for (auto x:m) {

                std::string z = x.str();
                std::smatch m2;
                double a, b, c, d, e, f;
                if (shape == 0 || shape == 1) {
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
                    Shape *shape1;
                    if (shape == 0)
                        shape1 = new Rectangle(a, b);
                    else if (shape == 1)
                        shape1 = new Ellipse(a, b);
                    else {
                        std::vector<TwoDimensionalCoordinate *> triangleVector;
                        triangleVector.push_back(new TwoDimensionalCoordinate(a, b));
                        triangleVector.push_back(new TwoDimensionalCoordinate(c, d));
                        triangleVector.push_back(new TwoDimensionalCoordinate(e, f));
                        shape1 = new Triangle(triangleVector);
                    }

                    _vectors.push_back(shape1);
                } catch (std::string e) {
                }
            }
            input = m.suffix().str();
        }
    }

    std::string get_last_word(const std::string &s) {
        auto index = s.find_last_of(' ');
        return s.substr(++index);
    }
};

#endif
