#include <stdio.h>

//structure definitions

//structure of a linked list node. It contains an element

struct node {
    int element;
    struct node *next;
};

/* structure of a linked list / head. Stores count of number of elements in the list, also a pointer to the head of the list */

struct linkedList {
    int count;
    struct node *first;
};

//function declarations

void insertFirst (struct linkedList *head, int ele);
struct node* deleteFirst(struct linkedList *head);
void printList (struct linkedList *head);
int search(struct linkedList *head, int ele);
struct node * delete (struct linkedList * head, int ele);