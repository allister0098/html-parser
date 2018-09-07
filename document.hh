#ifndef DOCUMENT_HH
#define DOCUMENT_HH

#include "node.hh"

class Document : public Node {
  public:
    Document();
    virtual ~Document();
    std::string nodeName();
};

#endif

