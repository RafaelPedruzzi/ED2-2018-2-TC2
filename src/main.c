// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// main.c: Program's entry point

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "worstFit.c"
#include "bestFit.c"

int main(int argc, char *argv[])
{
    int i;                              // Incrementation variable
    int numberOfElements;               // Number os elements in the problem
    int *values;                        // Array with all elements
    FILE *input = fopen(argv[1],"r");   // Input file containing the problem's elements

    fscanf(input, "%d", &numberOfElements); // Reading the number of elements

    values = malloc(numberOfElements*sizeof(int));  // Allocating the vaues array

    for(i = 0; i < numberOfElements; i++) { // Storing each value in the array
        fscanf(input, "%d", values[i]);
    }

    fclose(input);  // Closing input file

    for(i = 0; i < numberOfElements; i++) {
        printf("values[%d] = %d\n", i, values[i]);
    }

    return 0;
}