#include "linkedlist.h"

struct Stack {
    struct linkedList *l;
};

//function declarations
void push(struct Stack *head, int ele);
struct node* pop(struct Stack *head);