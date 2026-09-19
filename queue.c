#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
Queue *InitQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(q == NULL) {
        return NULL; // 内存分配失败
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}
int IsEmpty(Queue *q) {
    if(q == NULL) {
        return 1; // 队列不存在，视为空
    }
    if(q->front == NULL) {
        return 1;
    }
    return 0;
}
int QueueFull(Queue *q) {
    return 0; // 链式队列不会满
}
int QueueLength(Queue *q) {
    if(q == NULL) {
        return 0; // 队列不存在
    }
    int length = 0;
    QueueNode *current = q->front;
    while(current!=NULL){
        length++;
        current = current->next;
    }
    return length;
}
int Enqueue(Queue *q, int data) {
    if(q == NULL) {
        return 0; // 队列不存在
    }
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if(newNode == NULL) {
        return 0; // 内存分配失败
    }
    newNode->data = data;
    newNode->next = NULL;
    if(q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return 1;
}
int Dequeue(Queue *q, int *data) {
    if(q == NULL || data == NULL) {
        return 0; // 队列为空或参数无效
    }
    if(IsEmpty(q)){
        printf("队列为空，无法出队！\n");
        return 0;
    }
    QueueNode *temp = q->front;
    *data = temp->data;
    q->front = q->front->next;
    if(q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return 1;
}
void PrintQueue(Queue *q) {
    if(q == NULL) {
        printf("队列不存在！\n");
        return;
    }
    if(IsEmpty((q))) {
        printf("队列为空！\n");
        return;
    }
    QueueNode *current = q->front;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}
void FreeQueue(Queue *q) {
    QueueNode *current = q->front;
    while(current !=NULL) {
        QueueNode *temp = current;
        current = current->next;
        free(temp);
    }
    q = NULL;
}
int main() {
    Queue *q = InitQueue();
    if(q == NULL) {
        printf("队列初始化失败！\n");
        return 1;
    }
    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    PrintQueue(q);
    printf("\n");
    int data;
    Dequeue(q, &data);
    printf("出队元素: %d\n", data);
    PrintQueue(q);
    printf("\n");
    FreeQueue(q);
    return 0;
}
