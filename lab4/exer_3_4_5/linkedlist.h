#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
};

struct linkedlist
{
    int size;
    struct node *head;
};

void *myalloc(int x);
void myfree(void *x);
struct linkedlist *createList(int N);
void insertFirst(struct linkedlist *head, int ele);
struct node *deleteFirst(struct linkedlist *head);
void printlist(struct linkedlist *head);
struct linkedlist *createCycle(struct linkedlist *head);