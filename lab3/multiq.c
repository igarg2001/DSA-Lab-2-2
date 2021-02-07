#include "multiq.h"

MultiQ createMQ(int num)
{
    MultiQ mq;
    mq.size = num;
    mq.q = malloc(sizeof(Queue) * num);
    for (int i = 0; i < num; ++i)
    {
        mq.q[i] = newQ();
    }
    return mq;
}

MultiQ addMQ(MultiQ mq, Task t)
{
    Element newE = newElement(t.id);
    mq.q[t.pri - 1] = addQ(mq.q[t.pri - 1], newE);
    return mq;
}

Task nextMQ(MultiQ mq)
{
    if (isEmptyMQ(mq) == 1)
    {
        Task emptyTask;
        emptyTask.id = -1;
        emptyTask.pri -= 1;
        return emptyTask;
    }
    int i = highestPriority - 1;
    while (isEmpty(mq.q[i]))
        ++i;
    Task newTask;
    newTask.id = front(mq.q[i]).value;
    newTask.pri = i + 1;
    return newTask;
}

MultiQ delNextMq(MultiQ mq)
{
    if (isEmptyMQ(mq) == 1) 
        return mq;
    int i = 0;
    while (isEmpty(mq.q[i])==1) {
        ++i;
    }
   mq.q[i] = delQ(mq.q[i]);
    return mq;
}

int isEmptyMQ(MultiQ mq)
{
    for (int i = mq.size - 1; i >= 0; --i)
    {
        if (isEmpty(mq.q[i]))
            continue;
        return 0;
    }
    return 1;
}

int sizeMQ(MultiQ mq)
{
    int size = 0;
    for (int i = mq.size - 1; i >= 0; --i)
        size += lengthQ(mq.q[i]);
    return size;
}

int sizeMQbyPriority(MultiQ mq, Priority p)
{
    return lengthQ(mq.q[p - 1]);
}

Queue getQueueFromMQ(MultiQ mq, Priority p)
{
    return mq.q[p - 1];
}