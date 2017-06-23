#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define MAX_SIZE 64

struct heap
{
	int items[MAX_SIZE];
	int top;
};

Heap* heap__create(void)
{
	Heap *heap = (Heap*) malloc(sizeof(Heap));
	heap->top = 0;
	return heap;
}

void heap__destroy(Heap **heap)
{
	if (*heap != NULL)
		free(*heap);

	*heap = NULL;
}

void heap__push(Heap *heap, int value)
{
	if (heap->top == MAX_SIZE)
		return;

	heap->items[heap->top++] = value;
}

int heap__pop(Heap *heap)
{
	return heap->top ? heap->items[--heap->top] : -1;
}

int heap__size(Heap *heap)
{
	return heap->top;
}

int heap__top(Heap *heap)
{
	return heap->top ? heap->items[heap->top - 1] : -1;
}

void heap__print(Heap *heap)
{
	printf("[ ");

	for (size_t i = 0; i < heap->top; i++)
		printf("%d ", heap->items[i]);

	printf("]\n");
}

Heap* heap__clone(Heap *heap)
{
	Heap *new_heap = heap__create();

	for (size_t i = 0; i < heap->top; i++)
		new_heap[i] = heap[i];

	new_heap->top = heap->top;

	return new_heap;
}

void heap__reverse(Heap *heap)
{
	for (size_t i = 0, j = heap->top - 1; i < j; i++, j--)
	{
		int tmp = heap->items[i];
		heap->items[i] = heap->items[j];
		heap->items[j] = tmp;
	}
}
