#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Node *L = (Node *)malloc(sizeof(Node));
    if (L == NULL) {
        return 1;
    }

    InitList(L);
    HeadInsert(L, 1);
    HeadInsert(L, 2);
    HeadInsert(L, 3);
    PrintLink(L);
    freeList(L);
    TailInsert(L, 4);
    TailInsert(L, 5);
    TailInsert(L, 6);
    PrintLink(L);
    int length = ListLength(L);
    printf("Length of the list: %d\n", length);
    Deldata(L, 2);
    PrintLink(L);
    freeList(L);
    free(L);
    return 0;
}
