#include <stdio.h>
#include <stdlib.h>
#include"stack.h"
#define MAXSIZE 100
Stack *InitStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s == NULL){
        return NULL;
    }
    s->data = (int *)malloc(MAXSIZE * sizeof(int));
    if(s->data == NULL){
        free(s);
        return NULL;
    }
    s->top = -1;
    return s;
}
int isEmpty(Stack *s) {
    if(s == NULL){
        return 0;
    }
    if(s->top == -1){
        return 1;
    }
    return 0;
}
int Push(Stack *s, int e) {
    if(s == NULL) {
        return 0;
    }
    if(s->top == MAXSIZE - 1) {
        printf("栈满，无法入栈！");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}
int Pop(Stack *s, int *e) {
    if(s == NULL) {
        return 0;
    }
    if(s->top == -1) {
        printf("栈空，无法出栈！");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}
int GetTop(Stack *s,int *e){
    if(s == NULL) {
        return 0;
    }
    if(s->top == -1) {
        printf("栈空，无法获取栈顶元素！");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}
void PrintStack(Stack *s) {
    if(s == NULL) {
        return;
    }
    if(s->top == -1) {
        printf("栈为空！");
        return;
    }
    int i = s->top;
    while(i !=-1) {
        printf("%d ",s->data[i]);
        i--;
    }
    printf("\n");
}
void FreeStack(Stack *s) {
    if(s == NULL) {
        return;
    }
    free(s->data);
    free(s);
}
int main() {
    Stack *s = InitStack();
    if(s == NULL) {
        printf("初始化栈失败！");
        return 0;
    }
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    PrintStack(s);
    int e;
    Pop(s, &e);
    printf("出栈元素：%d\n", e);
    GetTop(s, &e);
    printf("栈顶元素：%d\n", e);
    PrintStack(s);
    FreeStack(s);
    return 0;
}
