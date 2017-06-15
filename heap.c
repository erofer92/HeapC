#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define MAX_SIZE 64

struct heap
{
	int items[MAX_SIZE];
	int top;
};

Heap* heap_create(void)
{
	Heap *heap = (Heap*) malloc(sizeof(Heap));
    heap->top = 0;
	return heap;
}

void heap_destroy(Heap **heap)
{
	if (*heap != NULL)
        free(*heap);
	
    *heap = NULL;
}

void heap_push(Heap *heap, int value)
{
	if (heap->top == MAX_SIZE)
		return;

	heap->items[heap->top++] = value;
}

int heap_pop(Heap *heap)
{
	return heap->top ? heap->items[--heap->top] : -1;
}

int heap_size(Heap *heap)
{
	return heap->top;
}

int heap_top(Heap *heap)
{
	return heap->top ? heap->items[heap->top-1] : -1;
}

void heap_print(Heap *heap)
{
	printf("[ ");

	for(size_t i = 0; i < heap->top; i++)
		printf("%d ", heap->items[i]);

	printf("]\n");
}

Heap* heap_clone(Heap *heap)
{
    Heap *new_heap = heap_create();

	for (size_t i = 0; i < heap->top; i++)
		new_heap[i] = heap[i];

	new_heap->top = heap->top;
	
	return new_heap;
}

void heap_reverse(Heap *heap)
{
	for (size_t i = 0, j = heap->top - 1; i < j; i++, j--)
    {
		int tmp = heap->items[i];
		heap->items[i] = heap->items[j];
		heap->items[j] = tmp;
	}
}
