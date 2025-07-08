#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>

int* copy_argv_to_array(int argc, char* argv[]) {
    int* numbers = (int*) malloc((argc - 1) * sizeof(int));

    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(-1);
    }

    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = atoi(argv[i]);  // Não considerando o primeiro elemento que é o nome do processo chamador
    }

    return numbers;
}

void print_array(int array[], int length) {
    for(int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void quickSort_alg(int array[], int esquerda, int direita) {
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = array[(esquerda + direita) / 2];
    while(i <= j) {
        while(array[i] < x && i < direita) {
            i++;
        }
        while(array[j] > x && j > esquerda) {
            j--;
        }
        if(i <= j) {
            y = array[i];
            array[i] = array[j];
            array[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda) {
        quickSort_alg(array, esquerda, j);
    }
    if(i < direita) {
        quickSort_alg(array, i, direita);
    }
}

void quickSort(int array[], int length) {
    quickSort_alg(array, 0, length - 1);
}

void insertionSort(int array[], int length) {
    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void main(int argc, char* argv[]) {
    if (argc < 11) {
        fprintf(stderr, "Enter 10 numbers or more\n");
        exit(-1);
    }

    int *numbers = copy_argv_to_array(argc, argv);
    int length = argc - 1;
    clock_t c2, c1;
    float tmp;

    pid_t pid;
    pid = fork();
    if(pid < 0) {
        fprintf(stderr, "Fork fail");
        exit(-1);
    }
    else if (pid == 0) { // FILHO (PERCEBE PID = 0)
        printf("CHILD EXECUTING WITH pid = %d...\n", pid);
        c1 = clock();
        quickSort(numbers, length);
        c2 = clock();
        tmp = (float) (c2 - c1) * 1000 / CLOCKS_PER_SEC;
        printf("\nTIME TO EXECUTE ON THE CHILD: %f\n", tmp);
        print_array(numbers, length);
        printf("CHILD IS FINISHED\n");
        exit(1);
    } else { //PAI (RECEBE PID DO FILHO)
        printf("PARENT WITH PID %d WAITING FOR CHILD...\n", pid);
        wait(NULL); /* parent will wait for the child to complete */
        c1 = clock();
        insertionSort(numbers, length);
        c2 = clock();
        tmp = (float) (c2 - c1) * 1000 / CLOCKS_PER_SEC;
        printf("\nTIME TO EXECUTE ON THE PARENT: %f\n", tmp);
        print_array(numbers, length);
        printf("PARENT IS FINISHED\n");
        exit(0);
    } 
}