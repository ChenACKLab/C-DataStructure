#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct Node{
    int data;
    struct Node *next;
}Node;
int InitList(Node *L);
int HeadInsert(Node *L,int e);
int TailInsert(Node *L,int e);
int PosInsert(Node *L,int e,int pos);
int Deldata(Node *L,int pos);
void PrintLink(Node *L);
int ListLength(Node *L);
void freeList(Node *L);
#endif
