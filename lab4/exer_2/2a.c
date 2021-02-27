#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int random;
    int *data;
    double ratio = 15000.0 / RAND_MAX;
    while (1)
    {
        random = rand() * ratio;
        data = myalloc(sizeof(int) * random);
        printf("First address: %p, Last address: %p, Heapspace is %lld\n", data, &data, heapspace);
        /* code */
        //myfree(data);
    }
}
