#include "meaureTimes.h"

void timeForReading()
{
    CARD *card_arr;
    int size;
    FILE *results = fopen("results.txt", "w");
    char filename[10];
    struct timeval t1, t2;
    double elapsedTime;
    int fileToRead;
    for (int i = 1; i < 7; ++i)
    {
        fileToRead = pow(10, i);
        gettimeofday(&t1, NULL);
        sprintf(filename, "%d", fileToRead);
        card_arr = read_record(card_arr, filename, &size);
        gettimeofday(&t2, NULL);
        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        fprintf(results, "Read %d cards in %lf milliseconds. \n", fileToRead, elapsedTime);
    }
    fclose(results);
}

void timeForSorting()
{
    CARD *card_arr;
    int size;
    FILE *results = fopen("sortResults.txt", "w");
    char filename[10];
    struct timeval t1, t2;
    double elapsedTime;
    int fileToRead;
    for (int i = 1; i < 6; ++i)
    {
        fileToRead = pow(10, i);
        gettimeofday(&t1, NULL);
        sprintf(filename, "%d", fileToRead);
        card_arr = read_record(card_arr, filename, &size);
        insertionSort(card_arr, size);
        gettimeofday(&t2, NULL);
        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        fprintf(results, "Sorted %d cards in %lf milliseconds. \n", fileToRead, elapsedTime);
    }
    fclose(results);
}