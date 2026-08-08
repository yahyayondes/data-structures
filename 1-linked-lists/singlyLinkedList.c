#include "implementation.h"
#include <stdlib.h>

void addFront(intList *list, intNode *newNode)
{
    newNode->next = list->head;
    list->head = newNode;
    list->elemCount++;
}

void addEnd(intList *list, intNode *newNode)
{
    newNode->next = NULL;
    if (list->head == NULL)
    {
        addFront(list, newNode);
        return;
    }

    intNode *temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    list->elemCount++;
}

void addMiddle(intList *list, intNode *newNode, int pos)
{
    if (list->head == NULL || pos <= 0)
    {
        addFront(list, newNode);
        return;
    }

    intNode *prev = list->head;

    for (int i = 0; i < pos - 1 && prev->next != NULL; i++)
        prev = prev->next;

    newNode->next = prev->next;
    prev->next = newNode;
    list->elemCount++;
}

void removeFront(intList *list)
{
    if (list->head == NULL)
        return;

    intNode *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->elemCount--;
}

void removeEnd(intList *list)
{
    if (list->head == NULL)
        return;

    if (list->head->next == NULL)
    {
        free(list->head);
        list->head = NULL;
        list->elemCount--;
        return;
    }

    intNode *prev = list->head;
    while (prev->next->next != NULL)
    {
        prev = prev->next;
    }

    free(prev->next);
    prev->next = NULL;
    list->elemCount--;
}
void removeValue(intList *list, int target)
{
    if (list->head == NULL)
        return;

    if (list->head->data == target)
    {
        removeFront(list);
        return;
    }
    intNode *prev = list->head, *curr = list->head->next;

    while (curr != NULL && curr->data != target)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
        return;

    prev->next = curr->next;
    free(curr);
    list->elemCount--;
}

int length(intList *list) { return list->elemCount; }

int get(intList *list, int pos)
{
    if (pos <= 0 || pos > list->elemCount)
        return -1;

    intNode *pos_ptr = list->head;
    for (int index = 0; index < pos; index++)
    {
        pos_ptr = pos_ptr->next;
    }

    return pos_ptr->data;
}
