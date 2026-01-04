#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX_QSIZE 100

struct queue {
    int data[MAX_QSIZE];
    int front;
    int tail;
};

void print_queue(struct queue *q) {
    printf("\n -Elements in Queue = %d - \n", q->tail - q->front + 1);
    for (int i = q->front; i <= q->tail; i++) {
        printf("- %d -", q->data[i]);
    }
    printf("\n - - - - - - - - - - - - - - -\n");
}

int is_queue_full(struct queue *q) {
    if (q->tail == MAX_QSIZE - 1) {
        return 1;
    }
    return 0;
}

int is_queue_empty(struct queue *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

int dequeue(struct queue *q) {
    if (!is_queue_empty(q)) {
        printf("%d dequeued...\n", q->data[q->front]);
        q->data[q->front] = 0;
        q->front = q->front + 1;
        if (q->front > q->tail) {
            q->front = -1;
            q->tail = -1;
        }
        return 0;
    }
    return -1;
}

void enqueue(struct queue *q, int data) {
    if (!is_queue_full(q))
    { 
        if (q->front == -1) {
            q->front = 0;
        }
        q->tail = q->tail + 1;
        q->data[q->tail] = data;        
    } else {
        printf("Full Queue!!\n");
    }
    return;
}

void q_init(struct queue *q) {
    q->front = -1;
    q->tail = -1;
}

int main() {
    struct queue q = {0};
    q_init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    print_queue(&q);
    int a = dequeue(&q);
    print_queue(&q);
    int b = dequeue(&q);
    print_queue(&q);

    return 0;
}