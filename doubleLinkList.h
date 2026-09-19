#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode;
DNode *InitDLinkList();
int DLinkListHeadInsert(DNode *L, int e);
int DLinkListTailInsert(DNode *L, int e);
int DLinkListInsert(DNode *L, int pos, int e);
int DLinkListDelete(DNode *L, int pos);
void PrintDLinkList(DNode *L);
void freeDLinkList(DNode *L);

#endif // DOUBLELINKLIST_H
