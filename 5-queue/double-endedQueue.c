#include "double-endedQueueImplementation.h"
#include <stdlib.h>

void insertFront(Deque *dq)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = dq->front;
    newNode->prev = NULL;

    if (dq->front == NULL)
    {
        dq->front = dq->rear = newNode;
    }
    else
    {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
}

int eraseFront(Deque *dq)
{
    if (dq->front == NULL)
        return -1;
    Node *temp = dq->front;
    int val = temp->data;
    dq->front = dq->front->next;

    if (dq->front != NULL)
    {
        dq->front->prev = NULL;
    }
    else
    {
        dq->rear = NULL;
    }

    free(temp);
    return val;
}

int eraseRear(Deque *dq)
{
    if (dq->rear == NULL)
    {
        return -1;
    }

    Node *temp = dq->rear;
    int val = temp->data;
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
    {
        dq->rear->next = NULL;
    }
    else
    {
        dq->front = NULL;
    }

    free(temp);
    return val;
}