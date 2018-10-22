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

int compare(const void *a, const void *b);

int main(int argc, char *argv[])
{
    int i;                              // Incrementation variable
    int mimDisks=0;
    int numberOfElements;               // Number os elements in the problem
    int *values;                        // Array with all elements
    int *sorted;                       // Array with all elements sorted
    int wf, bf, dwf, dbf;               // Number of utilized disks for each heuristic
    FILE *input = fopen(argv[1],"r");   // Input file containing the problem's elements

    fscanf(input, "%d", &numberOfElements); // Reading the number of elements

    values = malloc(numberOfElements*sizeof(int));  // Allocating the values array
    sorted = malloc(numberOfElements*sizeof(int));  // Allocating the sorted values array

    for(i = 0; i < numberOfElements; i++) { // Storing each value in the arrays
        fscanf(input, "%d", &values[i]);
        sorted[i] = values[i];
        mimDisks += values[i];
    }

    printf("Mim = %d\n", mimDisks/1000000);

    fclose(input);  // Closing input file

    qsort(sorted, numberOfElements, sizeof(int), compare); // Sorting the 'sorted' array

    time_t start = clock();

    wf = worstFit(values, numberOfElements);

    bf = 0;

    dwf = worstFit(sorted, numberOfElements);

    dbf = 0;

    time_t end = clock();

    double totalTime = ((double)(end-start)) / CLOCKS_PER_SEC;

    printf("%d\n%d\n%d\n%d\nTime = %f", wf, bf, dwf, dbf, totalTime);

    free(values);
    free(sorted);

    return 0;
}

int compare(const void *a, const void *b)
{
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ib  - *ia; 
}
