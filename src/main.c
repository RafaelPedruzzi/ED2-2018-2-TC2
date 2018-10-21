// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// main.c: Program's entry point

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/worstFit.h"
#include "../inc/bestFit.h"

int main(int argc, char *argv[])
{
    int i;                              // Incrementation variable
    int mimDisks=0;
    int numberOfElements;               // Number os elements in the problem
    int *values;                        // Array with all elements
    int wf, bf, dwf, dbf;               // Number of utilized disks for each heuristic
    FILE *input = fopen(argv[1],"r");   // Input file containing the problem's elements

    fscanf(input, "%d", &numberOfElements); // Reading the number of elements

    values = malloc(numberOfElements*sizeof(int));  // Allocating the vaues array

    for(i = 0; i < numberOfElements; i++) { // Storing each value in the array
        fscanf(input, "%d", &values[i]);
        mimDisks += values[i];
    }

    printf("Mim = %d\n", mimDisks/1000000);

    fclose(input);  // Closing input file

    

    time_t start = clock();

    // wf = 

    // bf = 

    // dwf = 

    // dbf = 

    time_t end = clock();

    double totalTime = ((double)(end-start)) / CLOCKS_PER_SEC;

    printf("%d\n%d\n%d\n%d\nTime = %f", wf, bf, dwf, dbf, totalTime);

    return 0;
}