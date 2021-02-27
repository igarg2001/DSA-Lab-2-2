#include "linkedlist.h"

struct linkedlist *createList(int N)
{
    struct linkedlist *ls = (struct linkedlist *)myalloc(sizeof(struct linkedlist));
    ls->size = 0;
    ls->head = NULL;
    int ran;
    for (int i = 0; i < N; ++i)
    {
        ran = rand();
        insertFirst(ls, ran);
    }
    return ls;
}

void insertFirst(struct linkedlist *head, int ele)
{
    struct node *link = (struct node *)myalloc(sizeof(struct node));
    link->data = ele;
    link->next = head->head;
    head->head = link;
    ++head->size;
}

struct linkedlist *createCycle(struct linkedlist *head)
{
    int ran = rand();
    if (ran > RAND_MAX / 2)
    {
        printf("Linkedlist is not cyclic\n");
        return head;
    }
    else
    {
        printf("LInkedlist is cyclic\n");
        int a[head->size];
        int i = 0;
        struct node *link = head->head;
        while (link->next != NULL)
        {
            a[i] = link->data;
            ++i;
            link = link->next;
        }
        ran = rand();
        double ratio = ((double)head->size) / RAND_MAX;
        ran *= ratio;

        int elToCycle = a[ran];
        struct node *nodeToCycle = NULL;
        link = head->head;
        while (link->next != NULL)
        {
            if (link->data == elToCycle)
            {
                nodeToCycle = link;
            }
            link = link->next;
        }
        link->next = nodeToCycle;
        return head;
    }
}