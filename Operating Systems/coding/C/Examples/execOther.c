#include <stdio.h>       // Para as funções de entrada/saída padrão
#include <stdlib.h>      // Para a função exit()
#include <unistd.h>      // Para as funções fork(), getpid() e exec*()

int main() {
    char *args[]={"./other", NULL};

    printf("Init..., pid: %d\n", getpid());
    execv(args[0], args); //irá executar sob o mesmo PID porque não foi criado um processo novo separado, apenas SUBSTITUI O PROCESSO ATUAL por um novo processo. O pid seria diferente se utilizasse o comando fork(), que cria uma cópia separada do processo atual. 

    printf("THIS IS NOT EXECUTED...\n");
    printf("THIS IS NOT EXECUTED...\n");
    printf("THIS IS NOT EXECUTED...\n");

    return 0;
}