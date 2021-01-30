#include "linkedlist.h"
//#include <stdlib.h>

void insertFirst(struct linkedList *head, int ele)
{
    //create a node

    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->element = ele;
    link->next = head->first;
    head->first = link;
    head->count++;
}

struct node *deleteFirst(struct linkedList *head)
{
    struct node *temp = head->first;
    head->first = temp->next;
    head->count--;
    return temp;
}

void printList(struct linkedList *head)
{
    struct node *current = head->first;
    while (current != NULL)
    {
        if (current->next == NULL)
            printf("%d", current->element);
        else
            printf("%d -> ", current->element);
        current = current->next;
    }
}