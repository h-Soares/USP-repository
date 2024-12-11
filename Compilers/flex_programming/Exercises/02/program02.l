%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>

int uppercase_letters = 0;
int lowercase_letters = 0;
int numbers = 0;
%}

%%
[A-Z]       {uppercase_letters++;}
[a-z]       {lowercase_letters++;}
[0-9]       {numbers++;}
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
    printf("\nNumero de letras maiusculas: %d\n", uppercase_letters);
    printf("Numero de letras minusculas: %d\n", lowercase_letters);
    printf("Numero de numeros: %d\n", numbers);
    return 0;
}