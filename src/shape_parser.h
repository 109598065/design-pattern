#ifndef SHAPE_PARSER_H
#define SHAPE_PARSER_H

#include "./scanner.h"
#include "./shape_builder.h"

class ShapeParser {
public:
    ShapeParser(std::string input) {
        _scanner = new Scanner(input);
        _sb = new ShapeBuilder();
        // initialize a scanner for handling input.
        // initialize a shape builder for handling building shape.
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

            if (token == "Rectangle") {
                _scanner->nextToken();
                double argument1 = stod(_scanner->nextToken());
                _scanner->nextToken();
                double argument2 = stod(_scanner->nextToken());

                while (")" != _scanner->nextToken()) {
                    isValid = false;
                    _scanner->nextToken();
                }

                if (isValid)
                    _sb->buildRectangle(argument1, argument2);
            } else if (token == "Ellipse") {
                _scanner->nextToken();
                double argument1 = stod(_scanner->nextToken());
                _scanner->nextToken();
                double argument2 = stod(_scanner->nextToken());

                while (")" != _scanner->nextToken()) {
                    isValid = false;
                    _scanner->nextToken();
                }

                if (isValid)
                    _sb->buildEllipse(argument1, argument2);
            } else if (token == "Triangle") {
                _scanner->nextToken();
                double argument1 = stod(_scanner->nextToken());
                _scanner->nextToken();
                double argument2 = stod(_scanner->nextToken());
                _scanner->nextToken();
                double argument3 = stod(_scanner->nextToken());
                _scanner->nextToken();
                double argument4 = stod(_scanner->nextToken());
                _scanner->nextToken();
                double argument5 = stod(_scanner->nextToken());
                _scanner->nextToken();
                double argument6 = stod(_scanner->nextToken());

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