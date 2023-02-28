#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#define MAX_QUEUE_SIZE 5 // maximum number of items in queue

typedef struct {
    int front, rear; // front and rear pointers
    char* items[MAX_QUEUE_SIZE]; // array to hold queue items
} CircularQueue;

// function prototypes
CircularQueue* createQueue();
void destroyQueue(CircularQueue* q);
int isFull(CircularQueue* q);
int isEmpty(CircularQueue* q);
void enqueue(CircularQueue* q, char* item);
char* dequeue(CircularQueue* q);
void displayQueue(CircularQueue* q);

#endif
