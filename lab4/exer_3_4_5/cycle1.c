#include "cycle.h"

int testCyclic(struct linkedlist *list)
{
    struct node *hare = list->head;
    struct node *tort = list->head;
    if (hare == NULL)
        return 0;
    while (hare->next != NULL && hare->next->next != NULL)
    {
        tort = tort->next;
        hare = hare->next->next;
        if (tort == hare)
        {
            return 1;
        }
    }
    return 0;
}