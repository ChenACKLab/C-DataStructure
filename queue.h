#ifndef QUEUE_H
#define QUEUE_H
typedef struct QueueNode{
    int data;
    struct QueueNode *next;
}QueueNode;
typedef struct Queue{
    QueueNode *front;
    QueueNode *rear;
}Queue;
Queue *InitQueue();
int Enqueue(Queue *q, int data);
int Dequeue(Queue *q, int *data);
int IsEmpty(Queue *q);
int QueueFull(Queue *q);
int QueueLength(Queue *q);
void PrintQueue(Queue *q);
void FreeQueue(Queue *q);
#endif
