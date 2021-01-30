#include "stack.h"
#include <stdlib.h>

void push(struct Stack *head, int ele)
{
    insertFirst(head->l, ele);
}

struct node *pop(struct Stack *head)
{
    if(head->l->count==0)
        return NULL;
    return deleteFirst(head->l);
}