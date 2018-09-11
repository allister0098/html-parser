#ifndef HTML_DRIVER_HH
#define HTML_DRIVER_HH
#include <string>
#include <map>
#include "node.hh"
#include "html-parser.hh"
#include "document.hh"
#include "comment.hh"
#include "htmlHtmlElement.hh"

#define YY_DECL \
  yy::html_parser::symbol_type yylex (html_driver& driver)

YY_DECL;

class html_driver
{
private:
  Document document;

public:
  html_driver ();
  virtual ~html_driver ();

  int result;

  // Handling the scanner.
  void scan_begin ();
  void scan_end ();
  bool trace_scanning;

  // Run the parser on file F.
  // Return 0 on success.
  int parse (const std::string& f);
  std::string file;
  bool trace_parsing;

  // Error handling.
  void error (const yy::location& l, const std::string& m);
  void error (const std::string& m);

  // Handling the document.
  void addComment(const std::string data);

  void addHTML();
  void addNode(Node node);
};
#endif

