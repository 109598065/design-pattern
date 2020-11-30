#ifndef SHAPE_BUILDER_H
#define SHAPE_BUILDER_H

#include <stack>
#include <vector>
#include "./rectangle.h"
#include "./ellipse.h"
#include "./triangle.h"
#include "./compound_shape.h"

class ShapeBuilder {
public:
    ShapeBuilder() {
        _uniqueId = 0;
    }

    void buildRectangle(double length, double width) {
        Shape *r = new Rectangle(std::to_string(_uniqueId++), length, width);
        _pushdown.push(r);
    }

    void buildEllipse(double semiMajorAxes, double semiMinorAxes) {
        Shape *r = new Ellipse(std::to_string(_uniqueId++), semiMajorAxes, semiMinorAxes);
        _pushdown.push(r);
    }

    void buildTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(x1, y1));
        triangleVector.push_back(new TwoDimensionalCoordinate(x2, y2));
        triangleVector.push_back(new TwoDimensionalCoordinate(x3, y3));
        Shape *r = new Triangle(std::to_string(_uniqueId++), triangleVector);
        _pushdown.push(r);
    }

    void buildCompoundShapeBegin() {
        Shape *cs = new CompoundShape(std::to_string(_uniqueId++), std::list<Shape *>());

        _pushdown.push(cs);
        _pushdown.push(nullptr);
    }

    void buildCompoundShapeEnd() {
        std::stack<Shape *> s;

        while (_pushdown.top() != nullptr) {
            s.push(_pushdown.top());
            _pushdown.pop();
        }
        _pushdown.pop();
        while (!s.empty()){
            _pushdown.top()->addShape(s.top());
            s.pop();
        }
    }

    std::deque<Shape *> getResult() {
        std::deque<Shape *> result;

        while (!_pushdown.empty()) {
            result.push_back(_pushdown.top());
            _pushdown.pop();
        }
        return std::deque<Shape *>(result.rbegin(), result.rend());
    }

private:
    std::stack<Shape *> _pushdown;
    int _uniqueId;
};

#endif
