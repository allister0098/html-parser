#ifndef NODE_HH
#define NODE_HH

#include <string>
#include <list>

class Node {
  public:
    std::list<Node*> children; 

    virtual ~Node() {};
    Node() {}

    virtual std::string data() { return "node"; };
    virtual std::string nodeName() { return "node"; };
};

#endif

