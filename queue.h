#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H
#include "boolean.h"

// Node untuk Linked List
typedef struct tElmtQueue {
    int info;
    struct tElmtQueue *next;
} ElmtQueue;

// Queue dengan pointer Head dan Tail
typedef struct {
    ElmtQueue *HEAD;
    ElmtQueue *TAIL;
} Queue;

void initQueue(Queue *Q);
boolean isQueueEmpty(Queue Q);
void enqueue(Queue *Q, int x);
void dequeue(Queue *Q, int *x);
void printQueue(Queue Q);

#endif