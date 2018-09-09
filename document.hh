#ifndef DOCUMENT_HH
#define DOCUMENT_HH

#include "htmlElement.hh"

class Document : public HTMLElement {
  public:
    Document(){};
    virtual ~Document() {};
    std::string nodeName() { return "#document"; };
};

#endif

