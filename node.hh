#ifndef NODE_HH
#define NODE_HH

#include <string>
#include <list>

class Node {
  public:
    Node();
    virtual ~Node();
    std::list<Node*> children; 
    virtual std::string data();
    virtual std::string nodeName();
};

#endif

