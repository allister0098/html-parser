#ifndef COMMENT_HH
#define COMMENT_HH

#include <string>
#include "node.hh"

class Comment : public Node {
  private:
    std::string _data;

  public:
    Comment(std::string d) : _data(d) {
      nodeType = NodeType::Comment;
    };
    virtual ~Comment() {};
    std::string data() { return _data; };
    std::string nodeName() { return "#comment"; }
};

#endif

