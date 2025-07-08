#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h> 

int* create_and_fill_array(int length) {
    int* array = (int*) malloc(length * sizeof(int));

    for(int i = 0; i < length; i++) {
        array[i] = rand() % length; //numbers in: 0 to length - 1
    }
    return array;
}

int search_from_start(int* array, int length, int element) {
    for(int i = 0; i < length; i++) {
        if(array[i] == element) {
            printf("FILHO 1 ENCONTROU %d na POSICAO %d !\n", element, i);
            return i;
        }
    }
    return -1;
}

int search_from_final(int* array, int length, int element) {
    for(int i = length - 1; i >= 0; i--) {
        if(array[i] == element) {
            printf("FILHO 2 ENCONTROU %d na POSICAO %d !\n", element, i);
            return i;
        }
    }
    return -1;
}

void main(int argc, char* argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Enter the length of array\n");
        exit(-1);
    }
    
    if (atoi(argv[1]) > 128) {
        fprintf(stderr, "Max of 128 numbers allowed\n");
        exit(-1);
    }

    srand(time(NULL));
    pid_t pid1, pid2;
    int status;
    int length = atoi(argv[1]);
    int element = rand() % length;
    int* numbers = create_and_fill_array(length);

    pid1 = fork();
    if (pid1 < 0) {
        perror("Error creating child 1");
        exit(1);
    }
    if(pid1 == 0) {
        usleep(rand() % 1001);
        exit(search_from_start(numbers, length, element));
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("Error creating child 2");
        exit(1);
    }
    if(pid2 == 0) {
        exit(search_from_final(numbers, length, element));
    }

    pid_t finished_pid = wait(&status);
    if (finished_pid == pid1) {
        // O primeiro filho terminou, verifica seu código de saída
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if(exit_status == 255)
                printf("O primeiro filho terminou e não encontrou %d\n", element);
            else
                printf("O primeiro filho encontrou %d na posicao %d\n", element, WEXITSTATUS(status));
        }
    } else if (finished_pid == pid2) {
        // O segundo filho terminou, verifica seu código de saída
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if(exit_status == 255)
                printf("O segundo filho terminou e não encontrou %d\n", element);
            else
                printf("O segundo filho encontrou %d na posicao %d\n", element, WEXITSTATUS(status));
        }
    }
    wait(NULL);
    free(numbers);
}