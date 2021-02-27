#include "insertSort.h"
void insertInOrder(CARD *card_arr, int n, CARD newCard)
{
    CARD tempCard;
    CARD card = newCard;
    for (int i = 0; i < n; ++i)
    {
        if (card.card_no < card_arr[i].card_no)
        {
            tempCard = card;
            card = card_arr[i];
            card_arr[i] = tempCard;
        }
    }
}

void insertionSort(CARD *card_arr, int n) {
    if(n==0) {
        top = &n;
        return;
    }
    insertionSort(card_arr, n-1);
    insertInOrder(card_arr, n, card_arr[n-1]);
}