#include "heapImplementation.h"
#include <stddef.h>

static void swap(int *first, int *second)
{
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

void max_heapify(Heap *heap, int index)
{
    if (heap == NULL || heap->data == NULL || index < 0 || index >= heap->heap_size)
    {
        return;
    }

    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap->heap_size && heap->data[left] > heap->data[largest])
        {
            largest = left;
        }
        if (right < heap->heap_size && heap->data[right] > heap->data[largest])
        {
            largest = right;
        }
        if (largest == index)
        {
            return;
        }

        swap(&heap->data[index], &heap->data[largest]);
        index = largest;
    }
}

void build_max_heap(Heap *heap)
{
    int index;

    if (heap == NULL || heap->data == NULL || heap->heap_size < 0 || heap->heap_size > heap->length)
    {
        return;
    }

    for (index = heap->heap_size / 2 - 1; index >= 0; --index)
    {
        max_heapify(heap, index);
    }
}

void heap_sort(Heap *heap)
{
    int end;
    int original_size;

    if (heap == NULL || heap->data == NULL || heap->heap_size < 0 || heap->heap_size > heap->length)
    {
        return;
    }

    original_size = heap->heap_size;
    build_max_heap(heap);
    for (end = heap->heap_size - 1; end > 0; --end)
    {
        swap(&heap->data[0], &heap->data[end]);
        --heap->heap_size;
        max_heapify(heap, 0);
    }

    heap->heap_size = original_size;
}

int extract_max(Heap *heap, int *max)
{
    if (heap == NULL || heap->data == NULL || max == NULL || heap->heap_size <= 0 || heap->heap_size > heap->length)
    {
        return 0;
    }

    *max = heap->data[0];
    --heap->heap_size;

    if (heap->heap_size > 0)
    {
        heap->data[0] = heap->data[heap->heap_size];
        max_heapify(heap, 0);
    }

    return 1;
}

int insert(Heap *heap, int value)
{
    int index;

    if (heap == NULL || heap->data == NULL || heap->heap_size < 0 || heap->heap_size >= heap->length)
    {
        return 0;
    }

    index = heap->heap_size;
    heap->data[index] = value;
    ++heap->heap_size;

    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap->data[parent] >= heap->data[index])
        {
            break;
        }

        swap(&heap->data[parent], &heap->data[index]);
        index = parent;
    }

    return 1;
}
