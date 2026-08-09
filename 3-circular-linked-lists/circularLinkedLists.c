#include "implementation.h"
#include <stdlib.h>
#include <stdio.h>

void insertFront(intNode **cursor, intNode *newNode)
{
    if (*cursor == NULL)
    {
        pred->next = newNode;
        *cursor = newNode;
        return;
    }

    newNode->next = (*cursor)->next;
    (*cursor)->next = newNode;
}

void removeFront(intNode **cursor)
{
    if (*cursor == NULL)
    {
        return;
    }

    intNode *front = (*cursor)->next;

    if (front == *cursor)
    {
        *cursor = NULL;
    }
    else
    {
        (*cursor)->next = front->next;
    }

    free(front);
}

void removeBack(intNode **cursor)
{
    if (*cursor == NULL)
    {
        return;
    }

    if ((*cursor)->next == (*cursor))
    {
        free(cursor);
        *cursor = NULL;
        return;
    }

    intNode *temp = *cursor;

    while (temp->next != *cursor)
    {
        temp = temp->next;
    }

    temp->next = (*cursor)->next;
    free(*cursor);
    *cursor = temp;
}

void print(intNode **cursor)
{
    if (*cursor == NULL)
    {
        return;
    }
    intNode *start = (*cursor)->next;
    intNode *temp = start;

    do
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("Finished!");
}

intNode *circularToLinear(intNode *cursor)
{
    if (cursor == NULL)
    {
        return NULL;
    }

    intNode *head = cursor->next;
    cursor->next = NULL;
    return head;
}
