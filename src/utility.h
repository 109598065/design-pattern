#ifndef UTILITY_H
#define UTILITY_H

#include "node.h"
#include <queue>

template<class Filter>
std::deque<Node*> filterNode(Node* node, Filter filter) {
  std::deque<Node *> deque;

    Iterator *it = node->createIterator();

    try {
        it->first();
    } catch (std::string e) {
        throw std::string("Only folder can filter node!");
    }

    for (it->first(); !it->isDone(); it->next()) {
        Node *s = it->currentItem();
        if (filter(s))
            deque.push_back(s);
        Iterator *ita = s->createIterator();
        if (!ita->isDone()) {
            for (auto fs : filterNode(s, filter)) {
                deque.push_back(fs);
            }
        }
    }
    return deque;
    // access the node with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the nodes under the input node tree sturctur that match the given filter.
    // throw std::string "Only folder can filter node!" when the input node is not iterable.
}

class SizeFilter {
public:
    SizeFilter(double upperBound, double lowerBound) : _upperBound(upperBound), _lowerBound(lowerBound) {}
    bool operator() (Node* node) const {
      return _lowerBound <= node->size() && node->size() <= _upperBound;
    }
private :
  double _upperBound,_lowerBound;
};

#endif
