#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>

#ifndef CARD_H
#define CARD_H
typedef struct {
    unsigned long long card_no;
    char bank_code[6];
    char first_name[20];
    char last_name[20];
    char expiry_date[8];
} CARD;
#endif