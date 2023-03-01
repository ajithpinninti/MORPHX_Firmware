#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "main_config.h"

#define MAX_QUEUE_SIZE MAX_COMMANDS_PER_TIME
#define MAX_SIZE_PER_ITEM MAX_PER_COMMAND_SIZE



typedef struct {
    char items[MAX_QUEUE_SIZE][40];
    int front ;
    int rear ;
} CircularQueue;

void initQueue(volatile CircularQueue* q);
int isFull(volatile CircularQueue* q);
int isEmpty(volatile CircularQueue* q);
void enqueue(volatile CircularQueue* q, const char* item);
char * dequeue(volatile CircularQueue* q);
void displayQueue(volatile CircularQueue* q);

#endif
