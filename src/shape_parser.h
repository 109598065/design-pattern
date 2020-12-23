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

            try {
                token = _scanner->nextToken();
            } catch (std::string e) {
                break;
            }

            std::vector<std::string> vector;
            std::string temp;

            if (token == "Rectangle") {
                if ("(" == _scanner->nextToken()) {
                    while (")" != (temp = _scanner->nextToken())) {
                        if ("," != temp)
                            vector.push_back(temp);
                    }
                    if (vector.size() == 2) {
                        double argument1 = stod(vector[0]);
                        double argument2 = stod(vector[1]);
                        _sb->buildRectangle(argument1, argument2);
                    }
                }
            } else if (token == "Ellipse") {
                if ("(" == _scanner->nextToken()) {
                    while (")" != (temp = _scanner->nextToken())) {
                        if ("," != temp)
                            vector.push_back(temp);
                    }
                    if (vector.size() == 2) {
                        double argument1 = stod(vector[0]);
                        double argument2 = stod(vector[1]);
                        _sb->buildEllipse(argument1, argument2);
                    }
                }
            } else if (token == "Triangle") {
                if ("(" == _scanner->nextToken()) {
                    while (")" != (temp = _scanner->nextToken())) {
                        if ("," != temp)
                            vector.push_back(temp);
                    }
                    if (vector.size() == 6) {
                        double argument1 = stod(vector[0]);
                        double argument2 = stod(vector[1]);
                        double argument3 = stod(vector[2]);
                        double argument4 = stod(vector[3]);
                        double argument5 = stod(vector[4]);
                        double argument6 = stod(vector[5]);
                        _sb->buildTriangle(argument1, argument2, argument3, argument4, argument5, argument6);
                    }
                }
            } else if (token == "CompoundShape") {
                _scanner->nextToken();
                _sb->buildCompoundShapeBegin();
            } else if (token == "}") {
                _sb->buildCompoundShapeEnd();
            }
        }
    }

    std::deque<Shape *> getResult() {
        return _sb->getResult();
    }

private:
    Scanner *_scanner;
    ShapeBuilder *_sb;
};

#endif