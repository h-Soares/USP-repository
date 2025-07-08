#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void fibonacci(int terms_quantity) {
    int first = 0, second = 1, next;

    for(int i = 0; i < terms_quantity; i++) {
        if(i <= 1)
            next = i;
        else{
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
}

void main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Too many arguments\n");
        exit(-1);
    }

    pid_t pid;
    pid = fork();

    if(pid < 0) {
        fprintf(stderr, "Fork fail");
        exit(-1);
    }
    else if (pid == 0) { // FILHO (PERCEBE PID = 0)
        printf("CHILD EXECUTING WITH pid = %d...\n", pid);
        fibonacci(atoi(argv[1]));
        exit(1);
    } else { //PAI (RECEBE PID DO FILHO)
        printf("PARENT WITH PID %d WAITING FOR CHILD...\n", pid);
        wait(NULL); /* parent will wait for the child to complete */
        printf("\nCHILD IS FINISHED");
        exit(0);
    } 
}