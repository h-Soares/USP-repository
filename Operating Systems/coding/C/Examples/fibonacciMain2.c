#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

void main(int argc, char* argv[]) {
    pid_t pid;
    pid = fork();

    if(pid < 0) {
        fprintf(stderr, "Fork fail");
        exit(-1);
    }
    else if (pid == 0) { // FILHO (PERCEBE PID = 0)
        printf("CHILD EXECUTING WITH pid = %d...\n", pid);
        execlp("./fibo", argv[0], argv[1], NULL);
    } else { //PAI (RECEBE PID DO FILHO)
        printf("PARENT WITH PID %d WAITING FOR CHILD...\n", pid);
        wait(NULL); /* parent will wait for the child to complete */
        printf("\nCHILD IS FINISHED\n");
        exit(0);
    } 
}