%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>

int vowels = 0;
int consonants = 0;
%}

%%
[aeiouAEIOU]       {vowels++;}
[a-zA-Z]       {consonants++;}
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
    printf("\nNumero de vogais: %d\n", vowels);
    printf("Numero de consoantes: %d\n", consonants);
    return 0;
}