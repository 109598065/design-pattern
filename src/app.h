#ifndef APP_H
#define APP_H

#include "node.h"

class App : public Node {
public:
    App(std::string id, std::string name, double size) : Node(id,name,size) {
      _path = "";
      _size = size;
    }

    std::string route() const{
      return _path + "/" + name();
    }

    double size() const {
      return _size;
    }

    void updatePath(std::string path){
       _path = path;
    }
    // implement any functions inherit from Node that you think is suitable.
private:
    std::string _path;
    double _size;
};
#endif
