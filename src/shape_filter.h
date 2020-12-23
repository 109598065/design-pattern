#ifndef SHAPE_FILTER_H
#define SHAPE_FILTER_H

#include "./filter.h"

typedef bool (*Predicate)(Shape *);

class ShapeFilter : public Filter {
public:
    ShapeFilter(Predicate pred) {
        _pred = pred;
    }

    Filter *setNext(Filter *filter) {
        _next = filter;
        return _next;
    }

    std::list<Shape *> push(std::list<Shape *> shapes) {
        std::list<Shape *>::const_iterator it;
        for (it = shapes.begin(); it != shapes.end(); it++) {
            if (!_pred(*it)) {
                it = shapes.erase(it);
            }
        }
        if (_next)
            return _next->push(shapes);
        return shapes;
    }

private:
    Filter *_next;
    Predicate _pred;
};

#endif
