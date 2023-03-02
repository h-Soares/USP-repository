#include <stdio.h>
#include <stdlib.h>

int main() {
   int tamanhoN, tamanhoM, contadorTamanho = 0; 

   printf("Digite o tamanho do vetor N: ");
   scanf("%i", &tamanhoN); 

   printf("\nDigite o tamanho do vetor M: ");
   scanf("%i", &tamanhoM); 

   printf("\n");

   int vetorN[tamanhoN], vetorM[tamanhoM], i, j; //declaração dos vetores com seus tamanhos e das variáveis auxiliares

   for(i = 0; i < tamanhoN; i++) {
       printf("Digite o valor da %i posicao do vetor N: ", i + 1);
       scanf("%i", &vetorN[i]); 
   }

   printf("\n");

   for(j = 0; j < tamanhoM; j++) {
    printf("Digite o valor da %i posicao do vetor M: ", j + 1);
    scanf("%i", &vetorM[j]); 
   }

    for(i = 0; i < tamanhoN; i++) {
        for(j = 0; j < tamanhoM; j++) {
            if(vetorN[i] == vetorM[j]) {
               contadorTamanho++; //Aqui é declarado o tamanho do vetor intersecção com base nos valores iguais dos 2 vetores.
               break; //Esse break é necessário porque, se houver um elemento em comum que aparece mais de uma vez em um dos dois
            }         //vetores, contará apenas uma vez.
        }
    }

    printf("\n");

    int vetorIntersec[contadorTamanho], k = 0; //Aqui de fato é declarado o vetor intersecção e uma variável auxiliar k.

    while(k < contadorTamanho) {
        for(i = 0; i < tamanhoN; i++) {
            for(j = 0; j < tamanhoM; j++) {
                if(vetorN[i] == vetorM[j]) {
                    vetorIntersec[k] = vetorM[j]; //Preenche as posições do vetor intersecção com os valores em comum nos dois vetores.
                    k++;
                    break; //Para contabilizar apenas uma vez e não ficar repetindo o mesmo número.
                }
            }
        }
    }

    for(k = 0; k < contadorTamanho; k++) {
        for(i = 0; i < contadorTamanho; i++) {
            if(vetorIntersec[k] == vetorIntersec[i] && k != i) { //Aqui exclui e atribui espaço aos valores iguais do vetor intersecção, 
                vetorIntersec[k] = ' ';                         //não contando o mesmo índice.
            }
        }
    }

    printf("\nVETOR INTERSECCAO: \n\n");
    if(contadorTamanho == 0) //Se não houver elementos em comum, imprimirá uma mensagem de erro.
        printf("Os vetores nao possuem elementos em comum!");

    for(k = 0; k < contadorTamanho; k++) {
        if(vetorIntersec[k] != ' ') //Aqui irá imprimir o vetor intersecção, sem contar os iguais (que estão atribuídos com espaço)
        printf("%i ", vetorIntersec[k]);
    }

    printf("\n");

    return 0;
}
