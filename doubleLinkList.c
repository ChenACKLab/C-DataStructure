#include "doubleLinkList.h"
#include <stdlib.h>
#include <stdio.h>

DNode *InitDLinkList() {
   DNode *L = (DNode *)malloc(sizeof(DNode));
    if(L == NULL) {
        return NULL;
    }
    L->prior = NULL;
    L->next = NULL;
    return L;
}
int DLinkListHeadInsert(DNode *L, int e) {
    if(L == NULL) {
        printf("链表不存在！");
        return 0;
    }
    DNode *P = (DNode *)malloc(sizeof(DNode));
    if(P == NULL) {
        return 0;
    }
    P->data = e;
    P->next = L->next;
    P->prior = L;
    if(L->next != NULL) {
        L->next->prior = P;
    }
    L->next = P;
    return 1;
}
int DLinkListTailInsert(DNode *L, int e) {
    if(L == NULL){
        printf("链表不存在！");
        return 0;
    }
    DNode *p = (DNode *)malloc(sizeof(DNode));
    if(p == NULL){
        return 0;
    }
    p->data = e;
    DNode *tail = L;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    p->next = NULL;
    p->prior = tail;
    tail->next = p;
    return 1;
}
int DLinkListInsert(DNode *L, int pos, int e){
    if(L == NULL){
        printf("链表不存在！");
        return 0;
    }
    if(pos<1){
        printf("插入位置不合法！");
        return 0;
    }
    int i = 0;
    DNode *temp = L;
    while(i < pos-1){
        temp = temp->next;
        if(temp == NULL){
            printf("插入失败，该节点不存在！");
            return 0;
        }
        i++;
    }
    DNode *p = (DNode *)malloc(sizeof(DNode));
    if(p == NULL){
        return 0;
    }
    p->data = e;
    p->prior = temp;
    p->next = temp->next;
    if(temp->next != NULL) {
        temp->next->prior = p;
    }
    temp->next = p;
    return 1;
}
int DLinkListDelete(DNode *L, int pos){
    if(L == NULL){
        printf("链表不存在！");
        return 0;
    }
    if(pos<1){
        printf("删除位置不合法！");
        return 0;
    }
    DNode *p ;
    DNode *temp = L;
    int i  = 0;
    while(i < pos-1){
        temp = temp->next;
        if(temp == NULL){
            printf("删除位置不存在！");
            return 0;
        }
        i++;
    }
    p = temp->next;
    if(p == NULL){
        printf("删除位置不存在！");
        return 0;
    }
    temp->next = p->next;
    if(p->next != NULL) {
        p->next->prior = temp;
    }
    free(p);
    return 1;
}
void PrintDLinkList(DNode *L){
    if(L == NULL){
        return;
    }
    L = L->next;
    while(L!=NULL){
        printf("%d ",L->data);
        L = L->next;
    }
}
void freeDLinkList(DNode *L){
    if(L == NULL) {
        return;
    }
    DNode *temp;
    while(L->next!=NULL){
        temp = L->next;
        L->next = temp->next;
        free(temp);
    }
}
