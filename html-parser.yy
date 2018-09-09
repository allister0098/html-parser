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
  START_TAG
  END_TAG
  START_CMT
  END_CMT
;

%token <std::string>CHARACTER
%token <std::string>COMMENT
%token <int> NUMBER "number"

%printer { yyoutput << $$; } <*>;

%%
%start unit;
unit: characters html  { };


characters:
  %empty          {}
| characters html {};


html:
  CHARACTER characters { std::cout << $1 << std::endl; }
| COMMENT characters    { std::cout << $1 << std::endl; driver.addComment($1); } 
| START_TAG characters END_TAG {}

%%

void
yy::html_parser::error (const location_type& l,
                            const std::string& m)
{
	driver.error (l, m);
}

