#include "ArrayBasedImplementation.h"
#include <stdio.h>

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow!");
        return;
    }

    s->top++;
    s->data[s->top] = value;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Underflow!");
        return -1;
    }

    int value = s->data[s->top];
    s->top--;
    return value;
}

int top(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }

    return s->data[s->top];
}