#include <stdio.h>       // Para as funções de entrada/saída padrão
#include <stdlib.h>      // Para a função exit()
#include <sys/types.h>   // Para o tipo pid_t
#include <unistd.h>      // Para as funções fork(), getpid() e exec*()
#include <sys/wait.h>    // Para a função wait()
#define FIBO_TERMS 5

void fibonacci() {
    int first = 0, second = 1, next;

    printf("Fibonacci Series: ");
    for (int i = 0; i < FIBO_TERMS; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    printf("\n");
}

int main() {
    pid_t pid;
    pid = fork(); /* cria outro processo */
    if (pid < 0) { /* ocorreu erro na execução do Fork */
        fprintf(stderr, "Falha no Fork ");
        exit(-1);
    } else if (pid == 0) { /* processo filho */
        printf("Processo filho: %d\n", pid);
        fibonacci();
        exit(1);
    } else { /* processo pai */
        printf("Processo pai: %d\n", pid);
        wait(NULL); /* pai espera o término do filho */
        printf("Filho terminou \n");
        exit(0);
    }

    return 0;
}