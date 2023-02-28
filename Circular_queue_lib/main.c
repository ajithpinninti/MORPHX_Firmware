#include <stdio.h>
#include "src/circular_queue.h"

int main() {
    CircularQueue* q = createQueue();

    enqueue(q, "hello");
    enqueue(q, "world");
    enqueue(q, "how");
    enqueue(q, "are");
    enqueue(q, "you");

    enqueue(q,"Lastone");

    enqueue(q,"Lastone");

    displayQueue(q);

    printf("dequeed element :%s \n",dequeue(q) );

    enqueue(q,"Fyn");

    displayQueue(q);

    dequeue(q);

    displayQueue(q);

    // enqueue(q,"Lastone");



    
    // printf("%d",isFull(q));
    // printf("%d",q->rear);
    // // printf("%d",MAX_QUEUE_SIZE);
    // displayQueue(q);


    // dequeue(q);
    // dequeue(q);

    // displayQueue(q);

    // enqueue(q, "doing");
    // enqueue(q, "today");

    // displayQueue(q);

    // destroyQueue(q);

    // displayQueue(q);
    // printf("Dequed: %s \n",dequeue(q));

    // printf("Dequed: %s \n",dequeue(q));
    // printf("Dequed: %s \n",dequeue(q));
    // printf("Dequed: %s \n",dequeue(q));
    // printf("Dequed: %s \n",dequeue(q));


    // dequeue(q);

    // printf("is it Empty %d \n",isEmpty(q));
    return 0;
}