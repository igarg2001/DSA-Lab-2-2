#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
    FILE *fileptr = fopen(argv[1], "r");
    FILE *fileptr2 = fopen(argv[2], "w");
    struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList));
    while (!feof(fileptr))
    {
        int temp;
        fscanf(fileptr, "%d", &temp);
        // printf("%d ", temp);
        insertFirst(head, temp);
    }
    fclose(fileptr);
   // deleting first node struct node *deletedNode = deleteFirst(head);
   struct node * deletedNode = deleteFirst(head);
    printf("%d", deletedNode->element);
    printf("\n");
    printList(head);
    //printing to another file
    struct node *current = head->first;
    while (current != NULL)
    {
        fprintf(fileptr2, "%d\n", current->element);
        current = current->next;
    }
    fclose(fileptr2);
}