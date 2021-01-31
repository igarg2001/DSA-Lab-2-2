#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    FILE *fptr1 = fopen("stackInput.txt", "r");
    FILE *fptr2 = fopen("stackOutput.txt", "w");
    struct linkedList *ll = (struct linkedList *)malloc(sizeof(struct linkedList));
    ll->count = 0;
    struct Stack *stk = (struct Stack *)malloc(sizeof(struct Stack));
    stk->l = ll;
    //pushing into stack
    while (!feof(fptr1))
    {
        int temp;
        fscanf(fptr1, "%d", &temp);
        push(stk, temp);
    }
    fclose(fptr1);
    //popping from stack
    struct node *curr;
    while ((curr = pop(stk)) != NULL)
    {
        //printing to file
        fprintf(fptr2, "%d\n", curr->element);
        //printing to stdout
        printf("%d ", curr->element);
        curr = curr->next;
    }
    fclose(fptr2);
}