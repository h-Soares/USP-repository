#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// to compile: gcc ex4.c -o ex4 -lm -pthread
void* threadIsPrime(void* arg) {
    double* number = (double*) arg;

    for(double i = 2; i <= sqrt(*number); i++) {
        if(fmod(*number, i) == 0.0) {
            printf("%f is not a prime!\n", *number);
            free(number);
            return NULL;
        }
    }
    printf("%f is a prime!\n", *number);
    free(number);
}

void main(int argc, char* argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Enter one or more numbers\n");
        exit(-1);
    }

    int threadNumbers = argc - 1;
    pthread_t threads[threadNumbers];


    // Create a thread for each argument
    for (int i = 0; i < threadNumbers; i++) {
        double* number = malloc(sizeof(double));
        *number = atof(argv[i + 1]);

        if (pthread_create(&threads[i], NULL, threadIsPrime, (void*) number) != 0) {
            perror("Error creating thread");
            exit(-1);
        }
    }

    for(int i = 0; i < threadNumbers; i++) {
        pthread_join(threads[i], NULL);
    }
}