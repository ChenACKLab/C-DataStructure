#ifndef STACK_H
#define STACK_H
typedef struct Stack {
    int *data;
    int top;
} Stack;
Stack *InitStack();
int isEmpty(Stack *s);
int Push(Stack *s, int e);
int Pop(Stack *s, int *e);
int GetTop(Stack *s, int *e);
void PrintStack(Stack *s);
void FreeStack(Stack *s);
#endif // STACK_H
