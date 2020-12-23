#ifndef COMPOUND_SHAPE_H
#define COMPOUND_SHAPE_H

#include <list>
#include "./shape.h"
#include "./shape_iterator.h"

class CompoundShape : public Shape {
public:
    CompoundShape(std::string id, std::list<Shape *> shapes) : Shape(id, "transparent") {
//        if (shapes.empty()) {
//            throw std::string("This is not a compound shape!");
//        }
        _shapes = shapes;
    }

    double area() const {
        double area = 0.0;
        std::list<Shape *>::const_iterator it;
        for (it = _shapes.begin(); it != _shapes.end(); it++) {
            area += (*it)->area();
        }
        return area;
    }

    double perimeter() const {
        double perimeter = 0.0;
        std::list<Shape *>::const_iterator it = _shapes.begin();
        for (_shapes.begin(); it != _shapes.end(); it++) {
            perimeter += (*it)->perimeter();
        }
        return perimeter;
    }

    std::string info() const {
        std::string info = "Compound Shape {";
        std::list<Shape *>::const_iterator it;
        for (it = _shapes.begin(); it != _shapes.end(); it++) {
            info += (*it)->info();
            info += ((*it) != _shapes.back() ? ", " : "");
        }
        info += "}";
        return info;
    }

    void addShape(Shape *shape) {
        _shapes.push_back(shape);
    }

    void deleteShapeById(std::string id) {
        std::list<Shape *>::iterator it;
        for (it = _shapes.begin(); it != _shapes.end(); it++) {
            if ((*it)->id() == id) {
                _shapes.remove(*it);
                return;
            }
            try {
                return (*it)->deleteShapeById(id);
            }
            catch (std::string e) {
            }
        }
        throw std::string("Expected delete shape but shape not found");
    }

    Shape *getShapeById(std::string id) const {
        std::list<Shape *>::const_iterator it;
        for (it = _shapes.begin(); it != _shapes.end(); it++) {
            if ((*it)->id() == id) {
                return *it;
            }
            try {
                return (*it)->getShapeById(id);
            }
            catch (std::string e) {
            }
        }
        throw std::string("Expected get shape but shape not found");
    }

    std::string type() const {
        return "Compound Shape";
    }

    Iterator *createIterator() const {
        return new ShapeIterator<std::list<Shape *>::const_iterator>(_shapes.begin(), _shapes.end());
    }

    void accept(Visitor *visitor) {
        visitor->visit(this);
    }

private:
    std::list<Shape *> _shapes;
};

#endif
