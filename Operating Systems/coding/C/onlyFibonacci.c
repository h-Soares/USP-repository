#include <stdio.h>
#include <stdlib.h>

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
    printf("\n");
}

void main(int argc, char* argv[]) {
    printf("\nOTHER PROGRAM ! ! ! \n");
    fibonacci(atoi(argv[1]));
}