#ifndef HEAP_IMPLEMENTATION_H
#define HEAP_IMPLEMENTATION_H

typedef struct
{
    int *data;
    int length;
    int heap_size;
} Heap;

void max_heapify(Heap *heap, int index);
void build_max_heap(Heap *heap);
void heap_sort(Heap *heap);
int extract_max(Heap *heap, int *max);
int insert(Heap *heap, int value);

#
