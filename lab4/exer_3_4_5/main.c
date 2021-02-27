#include "cycle.h"
#include <sys/time.h>

long long heapspace = 0;

void *myalloc(int x)
{
    heapspace += x;
    int *address = malloc(x + 4);
    *address = x;
    return (((void *)address) + 4);
}

void myfree(void *x)
{
    int *toread = (int *)(x - 4);
    int size = *toread;
    heapspace -= size;
    free(toread);
}

int main()
{
    srand(time(0));
    int N = 50000000;
    struct timeval t1, t2;
    double elapsedTime;
    gettimeofday(&t1, NULL);
    struct linkedlist *list = createList(N);
    FILE *fp = fopen("heap.txt", "w");
    fprintf(fp, "Heapspace = %lld\n", heapspace);
    list = createCycle(list);

    int isCyclic = testCyclic(list);
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("Total time elapsed during cyclic determination is %f milliseconds. \n", elapsedTime);

    if (isCyclic)
        printf("The linkedlist is cyclic");
    else
        printf("The linkedlist is linear");
}