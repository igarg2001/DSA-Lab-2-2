#include <stdio.h>
#include <stdlib.h>

struct element
{
    int value;
    struct element *next;
};

typedef struct element Element;

struct queue
{
    Element *first;
    Element *last;
    int size;
};

typedef struct queue Queue;

Queue newQ();
int isEmpty(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element e);
int lengthQ(Queue q);
Element newElement(int value);