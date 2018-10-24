// Estrutura de Dados II - 2018 / 2 Trab-2
//
// Rafael Belmock Pedruzzi
//
// heap.h: heap definitions

#ifndef HEAP_H_

#define HEAP_H_

/**
 * Struct that implements a heap
 * 
 * Size = heap's current length
 * contents = heap's contents
 * Ps: contents[0] stores the heap's max size
*/
typedef struct
{
    int size;
    int *contents;
} Heap;

/**
 * Function that initialize a new heap
 * 
 * input: the max size of the new heap
 * output: pointer to the new Heap
*/
Heap *heap_Init(int maxSize);

/**
 * Function that destroys a given Heap
 * 
 * input: pointer to a given heap
 * pre-condition: Heap existent and allocated
 * post-condition: Heap freed from the memory
*/
void heap_Destroy(Heap *h);

/**
 * Function that insert a element in a given Heap
 * 
 * inputs: pointer to the Heap and integer to be inserted
 * pre-condition: Heap existent and allocated
 * post-condition: Heap contains the integer
*/
void heap_Insert(Heap *h, int value);

/**
 * Function that removes the max element of a given Heap
 * 
 * input: Pointer to the Heap
 * pre-condition: Heap existent and allocated
 * post-condition: max removed from the Heap
*/
int heap_RemoveMax(Heap *h);

/**
 * Function that fix upward the position of a element on a given index 
 * 
 * input: pointer to the Heap and index to the element
 * pre-condition: Heap existent and allocated and index lower than the heap current size
 * post-condition: element fixed up to the correct position
*/
void heap_FixUp(Heap *h, int index);

/**
 * Function that fix downward the position of a element on a given index 
 * 
 * input: pointer to the Heap and index to the element
 * pre-condition: Heap existent and allocated and index lower than the heap current size
 * post-condition: element fixed down to the correct position
*/
void heap_FixDown(Heap *h, int index);

#endif
