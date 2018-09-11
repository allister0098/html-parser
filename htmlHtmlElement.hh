#ifndef HTML_ELEMENT_ELEMENT_HH
#define HTML_ELEMENT_ELEMENT_HH

#include <iostream>
#include "htmlElement.hh"

// https://html.spec.whatwg.org/multipage/semantics.html#htmlhtmlelement
class htmlHTMLElement : public HTMLElement {
  public:
    virtual ~htmlHTMLElement() {};
    virtual std::string nodeName() { return "HTML"; };
};

#endif

