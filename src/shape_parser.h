#ifndef SHAPE_PARSER_H
#define SHAPE_PARSER_H

#include "./scanner.h"
#include "./shape_builder.h"

class ShapeParser {
public:
    ShapeParser(std::string input) {
        _scanner = new Scanner(input);
        _sb = new ShapeBuilder();
    }

    void parser() {

        while (1) {
            std::string token;
            bool isValid = true;

            try {
                token = _scanner->nextToken();
            } catch (std::string e) {
                break;
            }

            try {
                if (token == "Rectangle") {
                    _scanner->nextToken();
                    double argument1 = stringToDoubleCanTryCatch(_scanner->nextToken());
                    _scanner->nextToken();
                    double argument2 = stringToDoubleCanTryCatch(_scanner->nextToken());
                    
                    while (")" != _scanner->nextToken()) {
                        isValid = false;
                        _scanner->nextToken();
                    }

                    if (isValid)
                        _sb->buildRectangle(argument1, argument2);
                } else if (token == "Ellipse") {
                    _scanner->nextToken();
                    double argument1 = stringToDoubleCanTryCatch(_scanner->nextToken());
                    _scanner->nextToken();
                    double argument2 = stringToDoubleCanTryCatch(_scanner->nextToken());

                    while (")" != _scanner->nextToken()) {
                        isValid = false;
                        _scanner->nextToken();
                    }

                    if (isValid)
                        _sb->buildEllipse(argument1, argument2);
                } else if (token == "Triangle") {
                    _scanner->nextToken();
                    double argument1 = stringToDoubleCanTryCatch(_scanner->nextToken());
                    _scanner->nextToken();
                    double argument2 = stringToDoubleCanTryCatch(_scanner->nextToken());
                    _scanner->nextToken();
                    double argument3 = stringToDoubleCanTryCatch(_scanner->nextToken());
                    _scanner->nextToken();
                    double argument4 = stringToDoubleCanTryCatch(_scanner->nextToken());
                    _scanner->nextToken();
                    double argument5 = stringToDoubleCanTryCatch(_scanner->nextToken());
                    _scanner->nextToken();
                    double argument6 = stringToDoubleCanTryCatch(_scanner->nextToken());

                    while (")" != _scanner->nextToken()) {
                        isValid = false;
                        _scanner->nextToken();
                    }

                    if (isValid)
                        _sb->buildTriangle(argument1, argument2, argument3, argument4, argument5, argument6);
                } else if (token == "CompoundShape") {
                    _scanner->nextToken();
                    _sb->buildCompoundShapeBegin();
                } else if (token == "}") {
                    _sb->buildCompoundShapeEnd();
                }
            } catch (std::string e) {
            }
        }
    }

    std::deque<Shape *> getResult() {
        return _sb->getResult();
    }

private:
    Scanner *_scanner;
    ShapeBuilder *_sb;

    double stringToDoubleCanTryCatch(std::string str) {
        std::istringstream iss(str);
        double result;
        iss >> result;
        return result;
    }
};

#endif