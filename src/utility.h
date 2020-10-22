#ifndef UTILITY_H
#define UTILITY_H

#include <deque>

Shape *getShapeById(Shape *shape, std::string id) {
    Iterator *it = shape->createIterator();

    try {
        it->first();
    } catch (std::string e) {
        throw std::string("Only compound shape can get shape!");
    }

    for (it->first(); !it->isDone(); it->next()) {
        Shape *s = it->currentItem();
        if (s->id() == id) {
            return s;
        }
        Iterator *ita = s->createIterator();
        if (!ita->isDone()) {
            return getShapeById(s, id);
        }
    }

    throw std::string("Expected get shape but shape not found");
}

template<class Filter>
std::deque<Shape *> filterShape(Shape *shape, Filter filter) {
    std::deque<Shape *> deque;

    Iterator *it = shape->createIterator();

    try {
        it->first();
    } catch (std::string e) {
        throw std::string("Only compound shape can filter shape!");
    }

    for (it->first(); !it->isDone(); it->next()) {
        Shape *s = it->currentItem();
        if (filter(s))
            deque.push_back(s);
        Iterator *ita = s->createIterator();
        if (!ita->isDone()) {
            for (auto ff : filterShape(s, filter)) {
                deque.push_back(ff);
            }
        }
    }
    return deque;
}

class AreaFilter {
public:
    AreaFilter(double upperBound, double lowerBound) :
            _upperBound(upperBound), _lowerBound(lowerBound) {}

    bool operator()(Shape *shape) const {
        return _lowerBound <= shape->area() && shape->area() <= _upperBound;
    }

private:
    double _upperBound, _lowerBound;
};

class PerimeterFilter {
public:
    PerimeterFilter(double upperBound, double lowerBound) :
            _upperBound(upperBound), _lowerBound(lowerBound) {}

    bool operator()(Shape *shape) const {
        return _lowerBound <= shape->perimeter() && shape->perimeter() <= _upperBound;
    }

private:
    double _upperBound, _lowerBound;
};

class ColorFilter {
public:
    ColorFilter(std::string color) :
            _color(color) {}

    bool operator()(Shape *shape) const {
        return shape->color() == _color;
    }

private:
    std::string _color;
};

class TypeFilter {
public:
    TypeFilter(std::string type) :
            _type(type) {}

    bool operator()(Shape *shape) const {
        return shape->type() == _type;
    }

private:
    std::string _type;
};

#endif
