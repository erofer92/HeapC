
#ifndef HEAP_H
#define HEAP_H

typedef struct heap Heap;

extern
Heap* heap_create(void);

extern
void heap_destroy(Heap **heap);

extern
void heap_push(Heap *heap, int value);

extern
int heap_pop(Heap *heap);

extern
int heap_top(Heap *heap);

extern
int heap_size(Heap *heap);

extern
Heap* heap_clone(Heap *heap);

extern
void heap_reverse(Heap *heap);

extern
void heap_print(Heap *heap);

static const struct
{
    Heap* (*create) (void);
    void (*destroy) (Heap **heap);
    void (*push) (Heap *heap, int value);
    int (*pop) (Heap *heap);
    int (*top) (Heap *heap);
    int (*size) (Heap *heap);
    Heap* (*clone) (Heap *heap);
    void (*reverse) (Heap *heap);
    void (*print) (Heap *heap);
} const heap = {
    .create = heap_create,
    .destroy = heap_destroy,
    .push = heap_push,
    .pop = heap_pop,
    .top = heap_top,
    .size = heap_size,
    .clone = heap_clone,
    .reverse = heap_reverse,
    .print = heap_print
};

#endif // HEAP_H
