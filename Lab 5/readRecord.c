#include "readRecord.h"

CARD *read_record(CARD *card_arr, char *file, int *size) {
    int n = 5;
    card_arr = (CARD*)malloc(sizeof(CARD)*n);
    FILE *f = fopen(file, "r");
    if(f==NULL) {
        printf("The file could not be opened");
        exit(0);
    }
    CARD newCard;
    int i=0;
    while(!feof(f)) {
        		fscanf(f,"\"%llu,%[^,],%[^,],%[^,],%[^\"]\"\n",&(newCard.card_no),newCard.bank_code,newCard.expiry_date,newCard.first_name,newCard.last_name);
                card_arr[i] = newCard;
                ++i;
                if(i==n) {
                    n*=2;
                    card_arr = realloc(card_arr, sizeof(CARD)*n);
                }
    }
    fclose(f);
    *size = i;
    return card_arr;
}