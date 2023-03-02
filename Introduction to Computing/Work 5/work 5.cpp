#include <iostream>
#include <stdlib.h>
using namespace std;

int returnIndex(int *array, int arraySize, int number);
int main()
{
    //.... declara vetor e seu tamanho...

    return 0;
}

int returnIndex(int *array, int arraySize, int number)
{
    int firstOccurrence = -1;

    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == number)
        {
            firstOccurrence = i;
            break;
        }
    }
    return firstOccurrence;
}
