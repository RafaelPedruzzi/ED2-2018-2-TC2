// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// heap.c: heap structure implementation

#include <stdio.h>
#include <stdlib.h>

#include "../inc/heap.h"

// Auxiliar function that exchange two elements in the heap
static void exch(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function that initialize a new heap
Heap *heap_Init(int maxSize)
{
    Heap *new = malloc(sizeof(Heap));                   // Initializing Heap structure
    new->contents = malloc((maxSize+1)*sizeof(int));    // Initializing heap contents
    new->size = 0;                                      // Initializing heap current size
    new->contents[0] = maxSize;                         // Initializing heap max size

    return new;
}

//Function that destroys a given Heap
void heap_Destroy(Heap *h)
{
    free(h->contents);  // Freeing heap's contents
    free(h);            // Freeing Heap structure
}

//Function that insert a element in a given Heap
void heap_Insert(Heap *h, int value)
{
    if(h->size == h->contents[0]) { // Aborting function if heap is full
        return;
    }
    int i = ++h->size;              // Increasing heap's current size
    h->contents[i] = value;         // Adding value to the heap
    heap_FixUp(h,i);                // Fixing value's position
}

//Function that removes the max element of a given Heap
int heap_RemoveMax(Heap *h)
{
    if(h->size == 0) {                                  // Aborting the program if heap is empty
        printf("Error: heap is empty!\n");
        exit(1);
    }
    exch(&(h->contents[1]), &(h->contents[ h->size ])); // Exchenging first (max) and last elements in the heap
    h->size--;                                          // Decreasing heap's current size
    heap_FixDown(h,1);                                  // Fixing the exchanged element's position

    return h->contents[ h->size+1 ];                    // Returning max
}

//Function that fix upward the position of a element on a given index
void heap_FixUp(Heap *h, int index)
{
    if(h->size < index) {       // Aborting the program if index is bigger than heap's current size
        printf("Error: invalid index!\n");
        exit(1);
    }
    while(index/2 > 0 && h->contents[index] > h->contents[index/2]) {   // While root is smaler than element exchange them
        exch(&(h->contents[index]), &(h->contents[index/2]));           // Exchanging
        index = index/2;                                                // Updating index
    }
}

//Function that fix downward the position of a element on a given index
void heap_FixDown(Heap *h, int index)
{
    int k;                                                      // Auxiliar variable
    while(index*2 <= h->size) {                                 // While children belong to the heap:
        k = index*2;                                            // Seting auxiliar as left children
        if(k < h->size && h->contents[k] < h->contents[k+1]) {  // Selecting biggest children
            k++;
        }
        if(h->contents[k] <= h->contents[index]) {              // Break loop if biggest children is lower or equal it's root
            break;
        }
        exch(&(h->contents[k]), &(h->contents[index]));         // Else, exchange them
        index = k;                                              // And Update root
    }
}
