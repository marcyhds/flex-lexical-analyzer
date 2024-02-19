%option noyywrap
%option nodefault
%option outfile="lexer.c" header-file="lexer.h"

%{ 
  #include "configs.h"
%}

DIGITS [0-9]+
LETTER [A-Za-z]

%%

if { return token(TOK_IF, NULL_); }
then { return token(TOK_THEN, NULL_); }
else { return token(TOK_ELSE, NULL_); }

[ \n\t] { return token(TOK_WS, NULL_); }

({LETTER}|_)({LETTER}|_|{DIGITS})* { return token(TOK_ID, yytext); } 

(<|>|<=|>=|=|<>) { return token(TOK_RELOP, yytext); } 

{DIGITS} { return token(TOK_INT, yytext); }

{DIGITS}(\.{DIGITS})? { return token(TOK_FLOAT, yytext); } 

\/\*.*\*\/ { return token(TOK_COM, NULL_); } 

<<EOF>> { return token(TOK_EOF, "EOF"); }

[[:space:]] { }
. { return token(TOK_ERR, yytext); } 

%%

Token tok;
Token * token (char type[], char value[]) {

  if(type==TOK_EOF) return NULL;
  
  strcpy(tok.type, type);
  strcpy(tok.value, value);

  return &tok;
}