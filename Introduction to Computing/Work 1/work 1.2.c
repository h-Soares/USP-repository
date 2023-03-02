#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void iniciarJogo(); //Função para estilizar o jogo
int main() {
    srand(time(NULL));
    int respostaCerta = rand() % 101 /* Para sortear números entre 0 e 100*/, num, tentativas = 0;
    iniciarJogo();

    do {
        printf("Digite um numero: ");
        fflush(stdin);
        scanf("%i", &num);
        if(num < respostaCerta) {
            printf("\nO numero digitado eh MENOR que a resposta certa!\n\n");
            tentativas++;
        }
        if(num > respostaCerta) {
            printf("\nO numero digitado eh MAIOR que a resposta certa!\n\n");
            tentativas++;
        }
        if(num == respostaCerta) {
            tentativas++;
            printf("\nPARABENS!! Voce acertou o numero!\nNUMERO CORRETO: %i\tTENTATIVAS: %i\n", respostaCerta, tentativas);
        }
    } while(num != respostaCerta);

    return 0;
}
void iniciarJogo() {
    printf("|---------------------------|\n");
    printf("|JOGO DE ADIVINHAR UM NUMERO|\n");
    printf("|---------------------------|\n");
}
