%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
%}

DIGIT   [0-9]
DIGITS  {DIGIT}+
MONEY   R\$[ ]*{DIGITS},{DIGIT}{DIGIT}

%%
{MONEY} {printf("%s\n", yytext);}
[\n]                {}
.                   {}
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