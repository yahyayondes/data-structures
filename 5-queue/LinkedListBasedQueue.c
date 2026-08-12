#include "LinkedListBasedImplementation.h"
#include <stdlib.h>

void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue *q, int val)
{
    Qnode *newNode = (Qnode *)malloc(sizeof(Qnode));
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
        return -1;

    Qnode *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return val;
}

int frontVal(Queue *q)
{
    if (q->front == NULL)
        return -1;

    return q->front->data;
}