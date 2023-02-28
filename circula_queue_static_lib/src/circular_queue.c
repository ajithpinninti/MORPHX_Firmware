#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_queue.h"

CircularQueue* createQueue() {
    CircularQueue* q = malloc(sizeof(CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void destroyQueue(CircularQueue* q) {
    free(q);
}

int isFull(CircularQueue* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

void enqueue(CircularQueue* q, const char* item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    strcpy(q->items[q->rear], item);
}

char * dequeue(CircularQueue* q) {
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

void displayQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        int i;
        printf("Queue contains:\n");
        for (i = q->front; i != q->rear; i = (
            i + 1) % MAX_QUEUE_SIZE) {
            printf("%s\n", q->items[i]);
        }
        printf("%s\n", q->items[i]);
    }
}
