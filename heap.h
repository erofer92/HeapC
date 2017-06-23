
#ifndef HEAP_H
#define HEAP_H

typedef struct heap Heap;

extern Heap* heap__create(void);

extern void heap__destroy(Heap **heap);

extern void heap__push(Heap *heap, int value);

extern int heap__pop(Heap *heap);

extern int heap__top(Heap *heap);

extern int heap__size(Heap *heap);

extern Heap* heap__clone(Heap *heap);

extern void heap__reverse(Heap *heap);

extern void heap__print(Heap *heap);

static const struct
{
    Heap* (*create)(void);
    void (*destroy)(Heap **heap);
    void (*push)(Heap *heap, int value);
    int (*pop)(Heap *heap);
    int (*top)(Heap *heap);
    int (*size)(Heap *heap);
    Heap* (*clone)(Heap *heap);
    void (*reverse)(Heap *heap);
    void (*print)(Heap *heap);
} heap = {
    .create = heap__create,
    .destroy = heap__destroy,
    .push = heap__push,
    .pop = heap__pop,
    .top = heap__top,
    .size = heap__size,
    .clone = heap__clone,
    .reverse = heap__reverse,
    .print = heap__print
};

#endif // HEAP_H
