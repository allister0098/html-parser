#ifndef HTML_ELEMENT_HH
#define HTML_ELEMENT_HH

#include <iostream>
#include <string>
#include "node.hh"

using namespace std;

// https://html.spec.whatwg.org/multipage/dom.html#htmlelement
class HTMLElement : public Node {
  private:
    std::string name;

  public:
    virtual ~HTMLElement() {};
    HTMLElement(std::string _tagName) { name = _tagName; }
    string title;

    std::string tagName() {
      return name;
    }
};

#endif

