#ifndef NODE_BUILDER_H
#define NODE_BUILDER_H

#include "folder.h"
#include <stack>

class NodeBuilder
{
public:
    NodeBuilder()
    {
        _uniqueId = 0;
    }

    void buildApp(std::string name, double size)
    {
        Node *r = new App(std::to_string(_uniqueId++), name, size);
        _pushdown.push(r);
    }

    void buildFolderBegin(std::string name)
    {
        Node *cs = new Folder(std::to_string(_uniqueId++), name);
        _pushdown.push(cs);
        _pushdown.push(nullptr);
    }

    void buildFolderEnd()
    {
        std::stack<Node *> s;

        while (_pushdown.top() != nullptr) {
            s.push(_pushdown.top());
            _pushdown.pop();
        }
        _pushdown.pop();
        while (!s.empty()){
            _pushdown.top()->addNode(s.top());
            s.pop();
        }
    }

    std::deque<Node *> getResult()
    {
        std::deque<Node *> result;

        while (!_pushdown.empty())
        {
            result.push_back(_pushdown.top());
            _pushdown.pop();
        }
        return std::deque<Node *>(result.rbegin(), result.rend());
    }

private:
    std::stack<Node *> _pushdown;
    int _uniqueId;
};

#endif