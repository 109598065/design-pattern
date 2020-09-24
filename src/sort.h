#ifndef SORT_H
#define SORT_H

#include "./shape.h"

template<class RandomAccessIterator, class Compare>
void quickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    if (first < last) {
        RandomAccessIterator p = _partition(first, last, comp);
        quickSort(first, p - 1, comp);
        quickSort(p + 1, last, comp);
    }
}

template<class RandomAccessIterator, class Compare>
RandomAccessIterator _partition(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    auto pivot = *last;
    RandomAccessIterator i = first;
    for (RandomAccessIterator j = first; j < last; j++) {
        if (comp(*j, pivot)) {
            std::swap(*i, *j);
            i = i + 1;
        }
    }
    std::swap(*i, *last);
    return i;
}

bool areaAscendingCompare(Shape *a, Shape *b) {
    return a->area() < b->area();
};

bool areaDescendingCompare(Shape *a, Shape *b) {
    return a->area() > b->area();
};

bool perimeterAscendingCompare(Shape *a, Shape *b) {
    return a->perimeter() < b->perimeter();
};

bool perimeterDescendingCompare(Shape *a, Shape *b) {
    return a->perimeter() > b->perimeter();
};

class AscendingCompare {
public:
    AscendingCompare(std::string feature) : _feature(feature) {
        _feature = feature;
    }

    bool operator()(Shape *a, Shape *b) {
        if (_feature == "area")
            return a->area() < b->area();
        else if (_feature == "perimeter")
            return a->perimeter() < b->perimeter();
        else
            throw std::string("This is not correct parameter.");
    }

private:
    std::string _feature;
};

class DescendingCompare {
public:
    DescendingCompare(std::string feature) : _feature(feature) {
        _feature = feature;
    }

    bool operator()(Shape *a, Shape *b) {
        if (_feature == "area")
            return a->area() > b->area();
        else if (_feature == "perimeter")
            return a->perimeter() > b->perimeter();
        else
            throw std::string("This is not correct parameter.");
    }

private:
    std::string _feature;
};

#endif