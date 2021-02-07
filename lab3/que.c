#include "que.h"

Queue newQ()
{
    Queue q;
    q.first = NULL;
    q.last = NULL;
    q.size = 0;
    return q;
}

int isEmpty(Queue q)
{
    if (q.size == 0)
        return 1;
    else
        return 0;
}

Queue delQ(Queue q)
{
    if (isEmpty(q))
        return q;
    if (q.size == 1)
    {
        q.size = 0;
        q.first = NULL;
        q.last = NULL;
        return q;
    }
    Element *temp = q.first;
    q.first = q.first->next;
    --q.size;
    return q;
}

Element front(Queue q)
{
    return *(q.first);
}

Queue addQ(Queue q, Element e)
{
    Element *el = malloc(sizeof(Element));
    el->value = e.value;
    el->next = e.next;
    if (isEmpty(q))
    {
        q.size = 1;
        q.first = q.last = el;
        return q;
    }
    Element *temp = q.last;
    temp->next = el;
    q.last = el;
    return q;
}

int lengthQ(Queue q)
{
    return q.size;
}

Element newElement(int value)
{
    Element e;
    e.value = value;
    e.next = NULL;
    return e;
}