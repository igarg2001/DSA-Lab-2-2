/***********file:   seqListOps.h *********/
#include "storage.h"

extern int initialize_elements(JobList list);
extern void sortJobList(JobList list, int size);
extern void printJobList(JobList list, int size );
extern SeqList createlist();
extern void insertelements(JobList list, int size, SeqList s[3]);
