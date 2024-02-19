#define TOK_ID "ID"       // id (identificadores)
#define TOK_RELOP "RELOP" // relop (operadores relacionais)
#define TOK_WS "WS"       // separadores (espaco, \t, \n)
#define TOK_INT "INT"     // numero inteiro
#define TOK_FLOAT "FLOAT" // numero flutuante
#define TOK_COM "COM"     // comentarios
#define TOK_EOF "EOF"     // eof
#define TOK_IF "IF"       // palavra reservada if
#define TOK_THEN "THEN"   // palavra reservada then
#define TOK_ELSE "ELSE"   // palavra reservada else
#define TOK_ERR "ERR"     // erro
#define NULL_ "-"         // null

typedef struct
{
  char type[10];
  char value[100];
} Token;

extern Token *token();
extern Token *yylex();