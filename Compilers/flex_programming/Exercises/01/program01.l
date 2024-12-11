%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>

int uppercase = 0;
%}

%%
[A-Z].*       {uppercase++;}
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
    printf("\nPalavras que começam com a letra maiuscula: %d\n", uppercase);
    return 0;
}