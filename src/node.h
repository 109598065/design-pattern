#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>
#include "./null_iterator.h"
#include "./visitor.h"

class Node
{
public:
        Node(std::string id, std::string name, double size);

        std::string id() const;

        std::string name() const;

        virtual std::string route() const;

        virtual double size() const;

        virtual void updatePath(std::string path);

        virtual void addNode(Node *node);

        virtual Node *getNodeById(std::string id) const;

        virtual void deleteNodeById(std::string id);

        virtual Iterator *createIterator() const;

        virtual ~Node();

        virtual void addNodes(std::list<Node*> nodes);
  
        virtual void accept(Visitor* visitor) = 0;


private:
        std::string _id, _name, _path;
        double _size;
};

#endif
