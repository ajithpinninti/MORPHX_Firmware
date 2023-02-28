#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#define MAX_QUEUE_SIZE 5

typedef struct {
    char items[MAX_QUEUE_SIZE][256];
    int front;
    int rear;
} CircularQueue;

CircularQueue* createQueue();
void destroyQueue(CircularQueue* q);
int isFull(CircularQueue* q);
int isEmpty(CircularQueue* q);
void enqueue(CircularQueue* q, const char* item);
void dequeue(CircularQueue* q);
void displayQueue(CircularQueue* q);

#endif
