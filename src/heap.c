// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// heap.c: heap structure implementation

#include <stdio.h>
#include <stdlib.h>

#include "../inc/heap.h"

void static exch(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function that initialize a new heap
Heap *heap_Init(int maxSize)
{
    Heap *new = malloc(sizeof(Heap));
    new->h = malloc((size+1)*sizeof(int));
    new->size = 0;
    new->h[0] = maxSize;

    return new;
}

//Function that destroys a given Heap
void heap_Destroy(Heap *h)
{
    free(h->h);
    free(h);
}

//Function that insert a element in a given Heap
void heap_Insert(Heap *h, int value)
{
    if(h->size == h->h[0]) {
        return;
    }
    int i = ++h->size;
    h->h[i] = value;
    heap_FixUp(h,i);
}

//Function that removes the max element of a given Heap
int heap_RemoveMax(Heap *h)
{
    exch(&(h->h[1]), &(h->h[ h->size ]));
    h->size--;
    heap_FixDown(h,1);

    return h->h[ h->size+1 ];
}

//Function that fix upward the position of a element on a given index
void heap_FixUp(Heap *h, int index)
{
    while(index/2 > 0 && h->h[index] > h->h[index/2]) {
        exch(&(h->h[index]), &(h->h[index/2]));
        index = index/2;
    }
}

//Function that fix downward the position of a element on a given index
void heap_FixDown(Heap *h, int index)
{
    int k;
    while(index*2 <= h->size) {
        k = index*2;
        if(k < h->size && h->h[k] < h->h[k+1]) {
            k++;
        }
        if(h->h[k] >= h->h[index]) {
            break;
        }
        exch(&(h->h[k]), &(h->h[index]))
        index = k;
    }
}
