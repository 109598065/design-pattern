#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    Shape(std::string id);

    Shape(std::string id, std::string color);

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    std::string id() const;

    std::string color() const;

    virtual void addShape(Shape *shape) {
        throw std::string("Only compound shape can add shape!");
    }

    virtual void deleteShapeById(std::string id) {
        throw std::string("Only compound shape can delete shape!");
    }

    virtual Shape *getShapeById(std::string id) {
        throw std::string("Only compound shape can get shape!");
    }

private:
    std::string _id, _color;
};

#endif