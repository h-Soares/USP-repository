%{
#include <stdio.h>
#include <stdlib.h>
// #include "y.tab.h"   // Incluir isso se for utilizar Bison para o parser (Análise Sintática)

/* Definição dos tokens usando enum */
enum Tags {
    IDENTIFIER,
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    EQUALS
};

/* Array de nomes dos tokens */
const char *tags_names[] = {
    "IDENTIFIER", "NUMBER", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "EQUALS"
};
%}

/* Definição de expressões regulares */
DIGIT       [0-9]
LETTER      [a-zA-Z_]
WHITESPACE  [ \t\n]+
ID          {LETTER}({LETTER}|{DIGIT})*
NUMBER      {DIGIT}+(\.{DIGIT}+)?

%%

{ID}        { printf("%s é um identificador!\n", yytext); }
{NUMBER}    { printf("%s é um número!\n", yytext);  }
"+"         { printf("%s\n", tags_names[PLUS]); }
"-"         { printf("%s\n", tags_names[MINUS]); }
"*"         { printf("%s\n", tags_names[MULTIPLY]); }
"/"         { printf("%s\n", tags_names[DIVIDE]); }
"="         { printf("%s\n", tags_names[EQUALS]); }
{WHITESPACE}   { /* Ignorar espaços em branco */ }
.          { printf("%s é um lexema inválido!\n", yytext); }

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Erro ao abrir arquivo");
            return 1;
        }
    }

    yylex();  // Chama o analisador léxico
    return 0;
}