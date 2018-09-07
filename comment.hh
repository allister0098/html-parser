#ifndef COMMENT_HH
#define COMMENT_HH

#include "node.hh"

//class Comment : public Node {
//  private:
//    std::string _data;
//
//  public:
//    Comment(std::string d) {
//      _data = d;
//    };
//    virtual ~Comment() {};
//    std::string data() override {
//      return _data;
//    };
//    std::string nodeName() override {
//      return "#comment";
//    };
//};

class Comment : public Node {
  private:
    std::string _data;

  public:
    Comment(std::string d);
    virtual ~Comment();
    std::string data();
    std::string nodeName();
};

#endif

