#ifndef FOLDER_H
#define FOLDER_H

#include <list>
#include "./node.h"
#include "./node_iterator.h"


class Folder : public Node {
public:
    Folder(std::string id, std::string name) : Node(id,name,0) {
      _path = "";
    }

    std::string route() const{
       return _path + "/" + name();
    }

    double size() const {
      double size = 0.0;
        std::list<Node *>::const_iterator it;
        for (it = _nodes.begin(); it != _nodes.end(); it++) {
            size += (*it)->size();
        }
      return size;
    }

    void updatePath(std::string path){
      _path = path;
      std::list<Node *>::const_iterator it;
      for (it = _nodes.begin(); it != _nodes.end(); it++) {
          (*it)->updatePath(path);
      }
    }

    void addNode(Node* node){
      node->updatePath(route());
      _nodes.push_back(node);
    }

    Node* getNodeById(std::string id) const{
      std::list<Node *>::const_iterator it;
        for (it = _nodes.begin(); it != _nodes.end(); it++) {
            if ((*it)->id() == id) {
                return *it;
            }
            try {
                return (*it)->getNodeById(id);
            }
            catch (std::string e) {
            }
        }
        throw std::string("Expected get node but node not found.");
    }

    void deleteNodeById(std::string id){
      std::list<Node *>::iterator it;
            for (it = _nodes.begin(); it != _nodes.end(); it++) {
                if ((*it)->id() == id) {
                    _nodes.erase(it);
                    return;
                }
                try {
                    return (*it)->deleteNodeById(id);
                }
                catch (std::string e) {
                }
            }
      throw std::string("Expected delete node but node not found.");
    }

    Iterator* createIterator() const{
       return new NodeIterator<std::list<Node *>::const_iterator>(_nodes.begin(), _nodes.end());
    }


private:
    std::list<Node*> _nodes;
    std::string _path;
};

#endif
