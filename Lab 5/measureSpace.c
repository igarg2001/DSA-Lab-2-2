#include "measureSpace.h"

void spaceForSorting()
{
    CARD *card_arr;
    int size;
    FILE *results = fopen("spaceResults.txt", "w");
    char filename[10];
    struct timeval t1, t2;
    double elapsedTime;
    int fileToRead;
    for (int i = 1; i < 6; ++i)
    {
        int a;
        fileToRead = pow(10, i);
        sprintf(filename, "%d", fileToRead);
        card_arr = read_record(card_arr, filename, &size);
        insertionSort(card_arr, size);
        fprintf(results, "Stack Space for %d records: %llu.\n",fileToRead, (unsigned long long)&a - (unsigned long long)top);
    }
    fclose(results);
}