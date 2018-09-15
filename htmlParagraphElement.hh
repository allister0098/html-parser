#ifndef HTML_PARAGRAPH_ELEMENT_HH
#define HTML_PARAGRAPH_ELEMENT_HH

#include <iostream>
#include "htmlElement.hh"

// https://html.spec.whatwg.org/multipage/grouping-content.html#htmlparagraphelement
class htmlParagraphElement : public HTMLElement {
  public:
    virtual ~htmlParagraphElement() {};
    htmlParagraphElement() : HTMLElement("P") {
      nodeType = NodeType::Paragraph;
    }
};

#endif

