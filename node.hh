#ifndef NODE_HH
#define NODE_HH

#include <string>
#include <list>

enum class NodeType {
  Node,
  Document,
  Comment,
  HTMLElement,
};

class Node {
  private:
    class base {
      public:
        virtual ~base() {};
        virtual base* clone() const = 0;
    };

    template<typename T>
    class type : public base {
      public:
        T node;
        type(T const& _node) : node(_node) {};
        base* clone() const { return new type<T>(*this); };
    };

    base* typePtr;

  public:
    NodeType nodeType;
    std::list<Node*> children;

    virtual ~Node() {};
    Node() {
      typePtr = new type<char>(0);
    }

    template<typename T>
    Node(T const& node) : typePtr(new type<T>(node)) {}

    std::string nodeName() {
      if (this->nodeType == NodeType::Document) {
        return "#document";
      } else if (this->nodeType == NodeType::Comment){
        return "#comment";
      } else if (this->nodeType == NodeType::HTMLElement){
        return "#html";
      } else {
        return "#node";
      }
    };

    template<typename T>
    inline const T& get() const {
      return static_cast<type<T>&>(*this->typePtr).node;
    }
};

#endif

