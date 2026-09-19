#ifndef SEQLIST_H
#define SEQLIST_H
#define MAXSIZE 100
struct seqlist{
    int *data;
    int length;
};
struct seqlist *InitList(struct seqlist *L);
int ListInsert(struct seqlist *L,int pos,int e);
int ListDelete(struct seqlist *L,int pos);
int GetElem(struct seqlist *L,int pos,int *e);
void PrintList(struct seqlist *L);
#endif // SEQLIST_H
