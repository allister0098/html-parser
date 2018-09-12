%{
  #include <cerrno>
  #include <climits>
  #include <cstdlib>
  #include <string>
  #include "html-driver.hh"
  #include "html-parser.hh"
  
  #undef yywrap
  #define yywrap() 1
  
  // The location of the current token.
  static yy::location loc;
  static std::string comment;
%}

%option noyywrap nounput batch debug noinput
%pointer
%array

htmlComment <!--.*?-->
htmlText    [^<]+
tagName     [[:alpha:]]+
id    [a-zA-Z][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t]

%{
  // Code run each time a pattern is matched.
  #define YY_USER_ACTION  loc.columns (yyleng);
%}

%x TAG_OPEN


%%

%{
  // Code run each time yylex is called.
  loc.step ();
%}
<<EOF>>            return yy::html_parser::make_END(loc);
{blank}+           loc.step ();
[\n]+              loc.lines (yyleng); loc.step ();

{htmlText}         return yy::html_parser::make_TEXT(yytext, loc);
{htmlComment}      return yy::html_parser::make_COMMENT(yytext, loc);
"</"                BEGIN(TAG_OPEN); return yy::html_parser::make_END_TAG_OPEN(loc);
"<"                 BEGIN(TAG_OPEN); return yy::html_parser::make_TAG_OPEN(loc);

<TAG_OPEN>">"      BEGIN(INITIAL);return yy::html_parser::make_TAG_CLOSE(loc);
<TAG_OPEN>"html"   return yy::html_parser::make_TAG_TYPE(htmlHTMLElement(), loc);
<TAG_OPEN>"p"      return yy::html_parser::make_TAG_TYPE(htmlParagraphElement(), loc);
                
%%


void
html_driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      error ("cannot open " + file + ": " + strerror(errno));
      exit (EXIT_FAILURE);
    }
}

void
html_driver::scan_end ()
{
  fclose (yyin);
}

