#include <stdio.h>
#include <stdlib.h>

#include "implementation.h"

static intNode *createNode(int value)
{
    intNode *node = malloc(sizeof *node);

    if (node == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->data = value;
    node->next = NULL;
    return node;
}

static void printList(const intList *list)
{
    const intNode *current = list->head;

    printf("Liste (%d eleman): ", list->elemCount);
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL)
            printf(" -> ");
    }
    printf("\n");
}

int main(void)
{
    intList list = {NULL, 0};

    addFront(&list, createNode(20));
    addFront(&list, createNode(10));
    printf("addFront sonrasi: ");
    printList(&list);

    addEnd(&list, createNode(40));
    printf("addEnd sonrasi:   ");
    printList(&list);

    addMiddle(&list, createNode(30), 2);
    printf("addMiddle sonrasi:");
    printList(&list);

    printf("length: %d\n", length(&list));
    printf("get(1): %d\n", get(&list, 1));

    removeValue(&list, 30);
    printf("removeValue(30):  ");
    printList(&list);

    removeFront(&list);
    printf("removeFront sonrasi: ");
    printList(&list);

    removeEnd(&list);
    printf("removeEnd sonrasi:   ");
    printList(&list);

    /* Kalan düğümleri serbest bırak. */
    while (list.head != NULL)
        removeFront(&list);

    return EXIT_SUCCESS;
}
