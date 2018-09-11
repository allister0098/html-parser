#ifndef NODE_HH
#define NODE_HH

#include <string>
#include <list>

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
    std::list<Node> children;

    virtual ~Node() {};
    Node() {
      typePtr = new type<char>(0);
    }

    template<typename T>
    Node(T const& node) : typePtr(new type<T>(node)) {}

    virtual std::string nodeName() { return "node"; };

    template<typename T>
    inline const T& get() const {
      return static_cast<type<T>&>(*this->typePtr).node;
    }
};

#endif

