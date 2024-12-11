%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>

typedef enum numb_type {INTEGER, FLOAT} numb_type;
void print_number(const char *text, numb_type type);
%}

DIGITS  [0-9]+
INTEGER_NUMB    {DIGITS}
FLOAT_NUMB  {DIGITS}(\.{DIGITS})? 

%%
{INTEGER_NUMB}      {print_number(yytext, INTEGER);}
{FLOAT_NUMB}        {print_number(yytext, FLOAT);}
[\n]                {}
.                   {}
%%

void print_number(const char *text, numb_type type) {
    switch(type) {
        case INTEGER:
            printf("INTEGER: %d\n", atoi(text));
            break;
        case FLOAT:
            printf("FLOAT: %f\n", atof(text));
            break;    
    }
}
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