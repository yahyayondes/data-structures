#include "LinkedListBasedImplementation.h"
#include <stdlib.h>
#include <stdio.h>

void initStack(Stack *s)
{
    s->head = NULL;
}

int isEmpty(Stack *s)
{
    return s->head == NULL;
}

void push(Stack *s, int value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));

    if (newNode == NULL)
    {
        return;
    }

    newNode->data = value;
    newNode->next = s->head;
    s->head = newNode;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Underflow");
        return -1;
    }

    StackNode *temp = s->head;
    int value = temp->data;

    s->head = s->head->next;
    free(temp);

    return value;
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }

    return s->head->data;
}