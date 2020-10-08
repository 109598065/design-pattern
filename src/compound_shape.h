#ifndef COMPOUND_SHAPE_H
#define COMPOUND_SHAPE_H

#include "./shape.h"

class CompoundShape : public Shape {
public:
    CompoundShape(std::string id, std::vector<Shape *> *shapes) : Shape(id, "transparent") {
        if (shapes->empty()) {
            throw std::string("This is not a compound shape!");
        }
        _shapes = shapes;
    }

    double area() const {
        double area = 0.0;
        std::vector<Shape *>::iterator it;
        for (it = _shapes->begin(); it < _shapes->end(); it++) {
            area += (*it)->area();
        }
        return area;
    }

    double perimeter() const {
        double perimeter = 0.0;
        std::vector<Shape *>::iterator it;
        for (it = _shapes->begin(); it < _shapes->end(); it++) {
            perimeter += (*it)->perimeter();
        }
        return perimeter;
    }

    std::string info() const {
        std::string info = "Compound Shape {";
        std::vector<Shape *>::iterator it;
        for (it = _shapes->begin(); it < _shapes->end(); it++) {
            info += (*it)->info();
            info += it != _shapes->end() - 1 ? ", " : "";
        }
        info += "}";
        return info;
    }

    void addShape(Shape *shape) {
        _shapes->push_back(shape);
    }

    void deleteShapeById(std::string id) {
        int size = _shapes->size();

        std::vector<Shape *>::iterator it;
        for (it = _shapes->begin(); it < _shapes->end(); it++) {
            if ((*it)->id() == id) {
                _shapes->erase(it);
            }
        }

        if (size == _shapes->size()) {
            throw std::string("Expected delete shape but shape not found");
        }
    }

    Shape *getShapeById(std::string id) {
        std::vector<Shape *>::iterator it;
        for (it = _shapes->begin(); it < _shapes->end(); it++) {
            if ((*it)->id() == id) {
                return *it;
            }
        }
        throw std::string("Expected delete shape but shape not found");
    }

private:
    std::vector<Shape *> *_shapes;
};

#endif
