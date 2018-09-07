#include "html-driver.hh"
#include "html-parser.hh"

html_driver::html_driver ()
  : trace_scanning (false), trace_parsing (false)
{
  document = Document();
  variables["one"] = 1;
  variables["two"] = 2;
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
  Node* comment = new Comment(data);
  document.children.push_back(comment);
}

