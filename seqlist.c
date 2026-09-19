#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"
struct seqlist *InitList(struct seqlist *L) {
    L = (struct seqlist *)malloc(sizeof(struct seqlist));
    L->data = (int *)malloc(MAXSIZE * sizeof(int));
    L->length = 0;
    return L;
}

int ListInsert(struct seqlist *L, int pos, int e) {
        if(pos<1||pos>L->length+1){
            printf("插入失败，pos不合法");
            return 0;
        }
        for(int i = L->length-1;i>=pos-1;i--){
            L->data[i+1] = L->data[i];
        }
        L->data[pos-1] = e;
        L->length++;
        return 1;
}

int ListDelete(struct seqlist *L, int pos) {
    if(pos<1||pos>L->length+1){
        printf("删除失败，pos不合法");
        return 0;
    }
    for(int i = pos-1;i<L->length-1;i++){
        L->data[i]=L->data[i+1];
    }
    L->length--;
    return 1;
}

int GetElem(struct seqlist *L, int pos, int *e) {
    if (pos < 1 || pos > L->length) {
        return 0;
    }
    *e = L->data[pos - 1];
    return 1;
}

void PrintList(struct seqlist *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int main(){
    struct seqlist *L ;
    L = InitList(L);
    ListInsert(L,1,10);
    ListInsert(L,2,20);
    ListInsert(L,3,30);
    ListInsert(L,4,40);
    PrintList(L);
    ListDelete(L,2);
    PrintList(L);
    return 0;
}
