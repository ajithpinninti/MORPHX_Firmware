#include <stdio.h>
#include "src/circular_queue.h"

int main() {
    CircularQueue* q = createQueue();

    enqueue(q, "apple");
    enqueue(q, "banana");
    enqueue(q, "cherry");
    enqueue(q, "date");
    enqueue(q, "elderberry");

    displayQueue(q);

    dequeue(q);
    dequeue(q);

    displayQueue(q);

    enqueue(q, "fig");
    enqueue(q, "grape");

    displayQueue(q);

    destroyQueue(q);

    return 0;
}
