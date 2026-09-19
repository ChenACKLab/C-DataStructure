#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
int InitList(Node *L){
    L->next = NULL;
    return  1;
}
int HeadInsert(Node *L,int e){
    Node *P = (Node *)malloc(sizeof(Node));
    P->data = e;
    P->next = L->next;
    L->next = P;
    return 1;
}
int TailInsert(Node *L,int e){
    Node *P = (Node *)malloc(sizeof(Node));
    P->data = e;
    P->next = NULL;
    Node *temp = L;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = P;
    return 1;
}
int PosInsert(Node *L,int e,int pos){
    Node *P = (Node *)malloc(sizeof(Node));
    P->data = e;
    Node *temp = L;
    for(int i = 0;i<pos-1;i++){
        if(temp->next == NULL){
            return 0;
        }
        temp = temp->next;
    }
    P->next=temp->next;
    temp->next = P;
    return 1;
}
int Deldata(Node *L,int pos){
    Node *temp = L;
    for(int i = 0;i<pos-1;i++){
        if(temp->next == NULL){
            return 0;
        }
        temp = temp->next;
    }
    Node *delNode = temp->next;
    if(delNode == NULL){
        printf("Position %d does not exist in the list.\n", pos);
        return 0;
    }
    temp->next = delNode->next;
    free(delNode);
    return 1;
}
void PrintLink(Node *L){
    Node *temp = L->next;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int ListLength(Node *L){
    int con = 0;
    Node *temp = L->next;
    while(temp!=NULL){
        con++;
        temp = temp->next;
    }
    return con;
}
void freeList(Node *L){
    Node *temp = L->next;
    while(temp!=NULL){
        Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    L->next = NULL;
}
