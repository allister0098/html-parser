#ifndef NODE_TREE_HH
#define NODE_TREE_HH

#include <list>
#include "node.hh"

class NodeTree {
  private:
    std::list<Node> children;

  public:
    NodeTree();
    virtual ~NodeTree();
    void appendChild(Node);
};


#endif
