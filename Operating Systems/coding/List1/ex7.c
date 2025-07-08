#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>

int collatz_conjecture(int number) {
    if(number % 2 == 0)
        return number / 2;
    return 3 * number + 1;
}

void collatz_procedure(int number) {
    printf("%d ", number);
    while(number != 1) {
        number = collatz_conjecture(number);
        printf("%d ", number);
    }
}

void main(int argc, char* argv[]) {
    if(argc != 2 || atoi(argv[1]) < 0) {
        fprintf(stderr, "Enter only a positive number\n");
        exit(-1);
    }
    
    pid_t pid;
    pid = fork();
    if(pid < 0) {
        fprintf(stderr, "Fork fail");
        exit(-1);
    }
    else if(pid == 0) {
        printf("CHILD EXECUTING WITH pid = %d...\n", pid);
        collatz_procedure(atoi(argv[1]));
        printf("\nCHILD IS FINISHED\n");
        exit(1);
    }else {
        printf("PARENT WITH PID %d WAITING FOR CHILD...\n", pid);
        wait(NULL);
        printf("PARENT IS FINISHED\n");
    }
}