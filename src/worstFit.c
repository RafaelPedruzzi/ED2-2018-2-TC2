// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// worstFit.c: worst fit and decreasing worst fit implementations

#include <stdio.h>
#include <stdlib.h>
#include "../inc/heap.h"

#include "../inc/worstFit.h"

// Worst fit heuristic function
int worstFit(int *values, int nValues)
{
    Heap *h = heap_Init(nValues);

    heap_Insert(h, DISK - values[0]);
    for(int i = 1; i < nValues; i++) {
        if(h->contents[1] >= values[i]) {
            h->contents[1] -= values[i];
            heap_FixDown(h, 1);
        } else {
            heap_Insert(h, DISK - values[i]);
        }
    }

    heap_Destroy(h);

    return h->size;
}
