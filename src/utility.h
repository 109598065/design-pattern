#ifndef UTILITY_H
#define UTILITY_H

#include "./node.h"
#include <queue>

template <class Filter>
std::deque<Node *> filterNode(Node *node, Filter filter)
{
    std::deque<Node *> deque;

    Iterator *it = node->createIterator();

    try
    {
        it->first();
    }
    catch (std::string e)
    {
        throw std::string("Only folder can filter node!");
    }

    for (it->first(); !it->isDone(); it->next())
    {
        Node *s = it->currentItem();
        if (filter(s))
            deque.push_back(s);
        Iterator *ita = s->createIterator();
        if (!ita->isDone())
        {
            for (auto fs : filterNode(s, filter))
            {
                deque.push_back(fs);
            }
        }
    }
    return deque;
}

class SizeFilter
{
public:
    SizeFilter(double upperBound, double lowerBound) : _upperBound(upperBound), _lowerBound(lowerBound) {}
    bool operator()(Node *node) const
    {
        return _lowerBound <= node->size() && node->size() <= _upperBound;
    }

private:
    double _upperBound, _lowerBound;
};

#endif
