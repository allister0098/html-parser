#include "dom-tree.hh"
#include "document.hh"

NodeTree::NodeTree() {
  Document document = Document();
  appendChild(document);
}

void NodeTree::appendChild(Node node) {
  children.push_front(node);
}

