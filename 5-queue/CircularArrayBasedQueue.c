#include "CircularArrayBasedImplementation.h"

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
    q->elemCount = 0;
}

void enqueue(Queue *q, int val)
{
    if (q->elemCount == LIMIT)
        return;

    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % LIMIT;
    q->elemCount++;
}

int dequeue(Queue *q)
{
    if (q->elemCount == 0)
        return -1;

    int val = q->data[q->front];
    q->front = (q->front + 1) % LIMIT;
    q->elemCount--;
    return val;
}

int frontVal(Queue *q)
{
    if (q->elemCount == 0)
        return -1;
    return q->data[q->front];
}
