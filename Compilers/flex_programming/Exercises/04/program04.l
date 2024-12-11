%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>

int characters = 0;
int words = 0;
int lines = 0;
%}

%%
[a-zA-Z]+       {words++; characters += yyleng;}
[\n]                {lines++;}
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
    printf("\nNumero de caracteres: %d\n", characters);
    printf("Numero de palavras: %d\n", words);
    printf("Numero de linhas: %d\n", lines);
    return 0;
}