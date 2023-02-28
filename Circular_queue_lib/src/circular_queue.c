#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_queue.h"

// create a new queue
CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*) malloc(sizeof(CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// destroy a queue
void destroyQueue(CircularQueue* q) {
    free(q);
}

// check if queue is full
int isFull(CircularQueue* q) {
    if ((q->front == 0 && q->rear == MAX_QUEUE_SIZE - 1) || (q->rear == (q->front - 1) % (MAX_QUEUE_SIZE - 1))) {
        return 1;
    } else {
        return 0;
    }
}

// check if queue is empty
int isEmpty(CircularQueue* q) {
    if (q->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

// add an item to the queue
void enqueue(CircularQueue* q, char* item) {
    if (isFull(q)) {
        printf("Queue is full.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->items[q->rear] = (char*) malloc(strlen(item) + 1);
        strcpy(q->items[q->rear], item);
    }
}

// remove an item from the queue
char* dequeue(CircularQueue* q) {
    char* item = NULL;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        }
    }
    return item;
}

// display the contents of the queue
void displayQueue(CircularQueue* q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contains:\n");
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%s\n", q->items[i]);
    }
    printf("%s\n", q->items[i]);
}
}