/***********file:   storage.h *********/
#include "job.h"
#define NO_OF_PRI 3

typedef struct
{
    Job ele;
    int next;
} Location;

typedef Location Store[MAX]; // MAX already defined in job.h

typedef struct
{
    int size;
    int head;
} SeqList;

typedef SeqList seqArray[NO_OF_PRI];

Store s;
