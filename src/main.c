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

/**
 * Auxiliar function that compare two integers. Used in qsort to sort the entry decreasingly.
 * 
 * input: two integers
 * output: <0 if a > b, =0 if a = b, >0 if a < b
*/
int compare(const void *a, const void *b);

/* main */
int main(int argc, char *argv[])
{
    int i; // Incrementation variable
    //long long int mimDisks = 0;
    int numberOfElements;              // Number os elements in the problem
    int *values;                       // Array with all elements
    int *sorted;                       // Array with all elements sorted
    int wf, bf, dwf, dbf;              // Number of utilized disks for each heuristic
    FILE *input = fopen(argv[1], "r"); // Input file containing the problem's elements

    time_t start = clock();

    fscanf(input, "%d", &numberOfElements); // Reading the number of elements

    values = malloc(numberOfElements * sizeof(int)); // Allocating the values array
    sorted = malloc(numberOfElements * sizeof(int)); // Allocating the sorted values array

    for (i = 0; i < numberOfElements; i++) // Storing each value in the arrays
    {
        fscanf(input, "%d", &values[i]);
        sorted[i] = values[i];
        //mimDisks += values[i];
    }

    //printf("Mim = %lld\n", mimDisks / 1000000);

    fclose(input); // Closing input file

    qsort(sorted, numberOfElements, sizeof(int), compare); // Sorting the 'sorted' array

    wf = worstFit(values, numberOfElements); // Executing worst fit

    bf = bestFit(values, numberOfElements); // Executing best fit

    dwf = worstFit(sorted, numberOfElements); // Executing decreasing worst fit

    dbf = bestFit(sorted, numberOfElements); // Executing decreasing best fit

    time_t end = clock();

    free(values);   // Freeing value's array
    free(sorted);   // Freeing sorted value's array

    double totalTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d\n%d\n%d\n%d\nTime = %f\n", wf, bf, dwf, dbf, totalTime); // Printing number of disks for each method

    return 0;
}

// Function that compare two integers
int compare(const void *a, const void *b)
{
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return *ib - *ia;
}
