#ifndef DOCUMENT_HH
#define DOCUMENT_HH

#include "node.hh"

class Document : public Node {
  public:
    Document() {
      nodeType = NodeType::Document;
    };
    virtual ~Document() {};
};

#endif

