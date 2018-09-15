%skeleton "lalr1.cc"
%require "3.0.4"
%defines
%define parser_class_name {html_parser}

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires
{
  #include <string>
  #include "node.hh"
  class html_driver;
}

// The parsing context.
%param { html_driver& driver }

%locations
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.file;
};

%define parse.trace
%define parse.error verbose

%code
{
  #include "html-driver.hh"
}

%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  TAG_OPEN
  END_TAG_OPEN
  TAG_CLOSE
;

%token <std::string>CHARACTER
%token <std::string>COMMENT
%token <Node>TAG_TYPE
%token <std::string>TEXT

%%
%start htmlElements;

htmlElements:
  %empty {}
| TEXT htmlElements { }
| htmlComment htmlElements {}
| htmlElement {}

htmlComment:
  COMMENT { driver.addComment($1); }

htmlElement:
  TAG_OPEN TAG_TYPE TAG_CLOSE htmlElements END_TAG_OPEN TAG_TYPE TAG_CLOSE
  {
    driver.addNode(&$2);
  }

%%

void
yy::html_parser::error (const location_type& l,
                            const std::string& m)
{
	driver.error (l, m);
}

