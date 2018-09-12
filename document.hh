#ifndef DOCUMENT_HH
#define DOCUMENT_HH

#include "htmlElement.hh"

class Document : public HTMLElement {
  public:
    Document(){
      nodeType = NodeType::Document;
    };
    virtual ~Document() {};
};

#endif

