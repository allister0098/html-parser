#include "comment.hh"

Comment::Comment(std::string d) {
  _data = d;
}

Comment::~Comment() {}

std::string Comment::data() {
  return _data;
}

std::string Comment::nodeName() {
  return "#comment";
}
