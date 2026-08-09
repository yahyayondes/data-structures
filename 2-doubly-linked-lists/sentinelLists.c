#include "sentinelLists.h"
#include <stdlib.h>

void initList(sentinelList *list)
{
    list->header = (intNode *)malloc(sizeof(intNode));
    list->tailer = (intNode *)malloc(sizeof(intNode));

    list->header->next = list->tailer;
    list->header->previous = NULL;
    list->tailer->previous = list->header;
    list->tailer->next = NULL;
}
void addBetween(intNode *newNode, intNode *pred, intNode *succ)
{
    newNode->previous = pred;
    newNode->next = succ;
    pred->next = newNode;
    succ->previous = newNode;
}

void insertFrontSentinel(sentinelList *list, intNode *newNode)
{
    addBetween(newNode, list->header, list->header->next);
}

void insertEndSentinel(sentinelList *list, intNode *newNode)
{
    addBetween(newNode, list->tailer->previous, list->tailer);
}

void removeSentinel(intNode *target)
{
    intNode *pred = target->previous;
    intNode *succ = target->next;
    pred->next = succ;
    succ->previous = pred;

    free(target);
}

int isEmptySentinel(sentinelList *list)
{
    return list->header->next == list->tailer;
}