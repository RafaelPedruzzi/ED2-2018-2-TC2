#include <stdio.h>
#include "../inc/heap.h"

void heapPrint(Heap *h)
{
    printf("Size = %d\n",h->size);
    for(int i = 0; i <= h->size; i++) {
        printf("%d = %d\n", i, h->contents[i]);
    }
}

int main(void)
{
    Heap *h = heap_Init(4);

    heapPrint(h);

    heap_Insert(h,1);
    heapPrint(h);
    heap_Insert(h,2);
    heapPrint(h);
    heap_Insert(h,3);
    heapPrint(h);
    heap_Insert(h,4);
    heapPrint(h);
    heap_Insert(h,5);
    heapPrint(h);

    heap_RemoveMax(h);
    heapPrint(h);

    heap_Destroy(h);

    return 0;
}