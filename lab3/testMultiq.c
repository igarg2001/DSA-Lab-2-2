#include "multiq.h"
#include <sys/time.h>

MultiQ loadData(FILE *f)
{
    MultiQ mq = createMQ(10);
    int a, b;
    Task t;
    while (!feof(f))
    {
        fscanf(f, "%d,%d", &a, &b);
        fgetc(f);
        t.id = a;
        t.pri = b;
        mq = addMQ(mq, t);
    }
    return mq;
}

MultiQ testDel(MultiQ mq, int num)
{
    if (isEmptyMQ(mq) == 1)
    {
        printf("MultiQ has become empty\n");
        return mq;
    }
    for (int i = 0; i < num; ++i)
    {
        delNextMq(mq);
    }
    return mq;
}

int main()
{
    struct timeval t1, t2, t3, t4;
    double elapsedTime1, elapsedTime2;
    FILE *f = fopen("input10000.txt", "r");
    gettimeofday(&t1, NULL);
    MultiQ mq = loadData(f);
    gettimeofday(&t2, NULL);
    fclose(f);
    //printf("%d", mq.q[0].size);
    elapsedTime1 = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime1 += (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("\nTotal time taken for loadData() is = %lf", elapsedTime1);
    gettimeofday(&t3, NULL);
    mq = testDel(mq, 10000);
    gettimeofday(&t4, NULL);
    elapsedTime2 = (t4.tv_sec - t3.tv_sec) * 1000.0;
    elapsedTime2 += (t4.tv_usec - t3.tv_usec) / 1000.0;
    printf("\nTotal time taken for testDel = %lf", elapsedTime2);
}