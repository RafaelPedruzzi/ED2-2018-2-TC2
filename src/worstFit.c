// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// worstFit.c: worst fit and decreasing worst fit implementations

#include <stdio.h>
#include <stdlib.h>
#include "../inc/heap.h"

#include "../inc/worstFit.h"

// Worst fit heuristic function.
int worstFit(int *values, int nValues)
{
    Heap *h = heap_Init(nValues);               // Initializing a simple heap. It will keep the remaining space of each disk.
    int nDisks;                                 // Number of disks needed.

    heap_Insert(h, DISK - values[0]);           // Inserting first element in the heap.
    for(int i = 1; i < nValues; i++) {          // For all other elements:
        if(h->contents[1] >= values[i]) {       // checks if it fit on the emptiest disk.
            h->contents[1] -= values[i];        // If id did, then decrease the remaining space in that disk.
            heap_FixDown(h, 1);                 // and fix down the disk.
        } else {                                // Else, insert it as a new disk.
            heap_Insert(h, DISK - values[i]);
        }
    }

    nDisks = h->size;                           // Getting the number of disks needed.

    heap_Destroy(h);                            // Freeing the heap.

    return nDisks;                              // Returning the number of disks needed.
}
