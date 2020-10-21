#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "iterator.h"
#include "null_iterator.h"
//class Iterator;

class Shape {
public:
    Shape(std::string id);

    Shape(std::string id, std::string color);

    std::string id() const;

    std::string color() const;

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    virtual std::string type() const = 0;

    virtual void addShape(Shape *shape);

    virtual void deleteShapeById(std::string id);

    virtual Shape *getShapeById(std::string id) const;

    virtual Iterator *createIterator() const; //todo to test

    virtual ~Shape(); //todo to note

private:
    std::string _id, _color;
};

#endif