#ifndef FIND_VISITOR_H
#define FIND_VISITOR_H

#include "./visitor.h"

class FindVisitor : public Visitor
{
public:
    FindVisitor(std::string name) : _name(name)
    {
        _result = "";
        isFirst = true;
    }

    void visitApp(App *app)
    {
        if (app->name() == _name)
        {
            _result += app->route();
        }
    }

    void visitFolder(Folder *folder)
    {
        Iterator *it = folder->createIterator();
        for (it->first(); !it->isDone(); it->next())
        {
            if (it->currentItem()->name() == _name){
                if(isFirst)isFirst = false ;
                else _result += '\n';
            }
            it->currentItem()->accept(this);
        }
         if (folder->name() == _name)
        {
            _result += folder->route();
        }
    }

    std::string getResult() const
    {
        return _result;
    }

private:
    std::string _name, _result;
    bool isFirst;
};

#endif