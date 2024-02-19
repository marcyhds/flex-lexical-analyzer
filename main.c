#include "configs.h"
#include "lexer.h"

int initialize(char *nome)
{
  FILE *f = fopen(nome, "r");

  if (f == NULL)
    return 0;

  yyin = f;

  return 1;
}

Token *next_token()
{
  return yylex();
}

void print_token(Token *tok)
{
  printf("<%s, %s>\n", tok->type, tok->value);
}

int main()
{
  Token *tok;

  char file_name[200];

  printf("Nome do arquivo: ");
  scanf("%s", file_name);
  initialize(file_name);

  tok = next_token();

  while (tok != NULL)
  {
    print_token(tok);
    tok = next_token();
  }

  return 0;
}

/*
  flex -DYY_DECL="Token *yylex()" lexic_rules.lex
  gcc -o a.out lexer.c main.c
  ./a.out
*/