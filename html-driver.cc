#include "html-driver.hh"
#include "html-parser.hh"

html_driver::html_driver ()
  :  trace_scanning (false), trace_parsing (false)
{
}

html_driver::~html_driver ()
{
}

int
html_driver::parse (const std::string &f)
{
  file = f;
  scan_begin ();
  yy::html_parser parser (*this);
  parser.set_debug_level (trace_parsing);
  int res = parser.parse ();
  scan_end ();
  return res;
}

void
html_driver::error (const yy::location& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}

void
html_driver::error (const std::string& m)
{
  std::cerr << m << '\n';
}

void
html_driver::addComment(const std::string data) {
  document.children.push_back(new Comment(data));
}

void
html_driver::addHTML() {
  document.children.push_back(new htmlHTMLElement());
}

void
html_driver::addNode(Node* node) {
  document.children.push_back(node);
}

