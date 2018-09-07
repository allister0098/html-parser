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

id    [a-zA-Z][a-zA-Z_0-9]*
cmt   [^->]+
int   [0-9]+
blank [ \t]
alpha [[:alpha:]]

%{
  // Code run each time a pattern is matched.
  #define YY_USER_ACTION  loc.columns (yyleng);
%}

%x TAG_OPEN
%x MARK_UP 
%x TAG_NAME 
%x CMT_S
%x CMT_S_D
%x CMT
%x CMT_E
%x CMT_E_D


%%

%{
  // Code run each time yylex is called.
  loc.step ();
%}
<<EOF>>            return yy::html_parser::make_END(loc);
{blank}+           loc.step ();
[\n]+              loc.lines (yyleng); loc.step ();

<CMT_E>">"         BEGIN(INITIAL); return yy::html_parser::make_COMMENT(comment, loc);
<CMT_E_D>"-"       BEGIN(CMT_E); 
<CMT>"-"           BEGIN(CMT_E_D); 
<CMT_S_D>{cmt}     BEGIN(CMT); comment = yytext; printf("%s", comment.c_str());
<CMT_S>"-"         BEGIN(CMT_S_D);
<MARK_UP>"-"       BEGIN(CMT_S);
<TAG_OPEN>{alpha}  BEGIN(TAG_NAME);
<TAG_OPEN>"!"      BEGIN(MARK_UP);
{alpha}            return yy::html_parser::make_CHARACTER(comment, loc);
"<"                BEGIN(TAG_OPEN); 
.                  driver.error (loc, "invalid character");

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

