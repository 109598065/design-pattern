#ifndef SHAPE_SETTER_H
#define SHAPE_SETTER_H

#include "./filter.h"

typedef void (*Setter)(Shape *);

class ShapeSetter : public Filter {
public:
    ShapeSetter(Setter set) {
        _set = set;
    }

    Filter *setNext(Filter *filter) {
        _next = filter;
        return _next;
    }

    std::list<Shape *> push(std::list<Shape *> shapes) {
        std::list<Shape *>::const_iterator it;
        for (it = shapes.begin(); it != shapes.end(); it++) {
            _set(*it);
        }
        if (_next)
            return _next->push(shapes);
        return shapes;
    }

private:
    Filter *_next;
    Setter _set;
};

#endif
