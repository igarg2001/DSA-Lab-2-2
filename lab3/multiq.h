#include "que.h"
#define highestPriority 1;

struct multiQ {
    int size;
    Queue *q;
};

typedef struct multiQ MultiQ;

typedef int Priority;
typedef int TaskId;
typedef struct {
    TaskId id;
    Priority pri;
} Task;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMq(MultiQ mq);
int isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ mq, Priority p);
