#include <stdio.h>
#include <math.h>

#ifdef __unix__  //para descobrir o sistema operacional do usuário.
    #include <unistd.h>
    #include <stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
   #define OS_Windows
   #include <windows.h>
#endif

int main() {

    int n1, n2, n3, n4, n5, flag = 0; //Flag para não realizar nenhuma operação sem ter lido os números antes.
    int resp, respDo;

    do {
        if(flag == 0)
            printf("NENHUM NUMERO DIGITADO!\n\n");
        if(flag == 1)
            printf("NUMEROS DIGITADOS: %i %i %i %i %i\n\n", n1, n2, n3, n4, n5);
        printf("0 - Ler valores\t\t1 - Media aritmetica simples\t2 - Media ponderada\t\n3- Desvio padrao\t4 - Maior valor e menor valor\n");
        printf("\nEscolha uma opcao do menu: ");
        scanf("%i", &resp);

        switch(resp) {
            case(0): {
                printf("Digite cinco numeros inteiros: ");
                scanf("%i%i%i%i%i", &n1, &n2, &n3, &n4, &n5);
                printf("\nLeitura dos numeros realizada!\n");
                flag = 1;
                break;
            }
            case (1): {
                if(flag == 0) {
                    printf("Nenhum valor lido ate o momento, impossivel realizar a operacao!\n");
                    break;
                }
                printf("A media aritmetica simples e: %f\n", (float)(n1 + n2 + n3 + n4 + n5)/5);
                break;
            }
            case (2): {
                if(flag == 0) {
                    printf("Nenhum valor lido ate o momento, impossivel realizar a operacao!\n");
                    break;
                }

                int p1, p2, p3, p4, p5;
                float mediap;
                printf("Digite os pesos \n");
                scanf("%i%i%i%i%i", &p1, &p2, &p3, &p4, &p5);
                if(p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0) {
                    printf("Impossivel dividir por zero!\n");
                    break;
                }
                mediap = ((n1 * p1) + (n2 * p2) + (n3 * p3) + (n4 * p5) + (n5 * p5))/(p1 + p2 + p3 + p4 + p5);
                printf("\nA media ponderada e: %f", mediap);
                break;
            }
            case (3): {
                if(flag == 0) {
                    printf("Nenhum valor lido ate o momento, impossivel realizar a operacao!\n");
                    break;
                }

                float media, somatorio, dpi, dpfim;
                media = (n1 + n2 + n3 + n4 + n5)/5;
                somatorio = ((n1 - media) * (n1 - media)) + ((n2 - media) * (n2 - media)) + ((n3 - media) * (n3 - media))  + ((n4- media) * (n4 - media))  
                            + ((n5 - media) * (n5 - media));
                dpi = (somatorio)/4;
                dpfim = sqrt (dpi);
                printf("O desvio padrao e: %f\n", dpfim);
                break;
            }
            case (4): {
                if(flag == 0) {
                    printf("Nenhum valor lido ate o momento, impossivel realizar a operacao!\n");
                    break;
                }

                int vetor[5] = {n1, n2, n3, n4, n5};
                int maior = vetor[0], menor = vetor[0], i;

                for(i = 1; i < 5; i++) {
                    if(vetor[i] > maior)
                        maior = vetor[i];
                    if (vetor[i] < menor)
                        menor = vetor[i];
                }

                if(maior == menor) {
                    printf("\nOs numeros sao iguais!");
                    break;
                }

                printf("\nO maior numero e: %i\n", maior);
                printf("O menor numero e: %i\n", menor);
                break;
            }
            default: {
                printf("Opcao invalida!\n");
                break;
            }    
        }
        printf("\n-1 para sair. Qualquer outra tecla para repetir o menu: ");
        fflush(stdin);
        scanf("%i", &respDo);

        #ifdef OS_Windows //Limpa tela para sistemas operacionais diferentes.
                //Codigo Windows
                system("cls");
        #else
                //Codigo GNU/Linux
                system("clear");
        #endif
            if(respDo == -1)
                printf("Saindo...\n");
    } while(respDo != -1);

    return 0;
}
