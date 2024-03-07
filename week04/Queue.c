#include "Stack.h"

struct queue {
    Stack s1;
    Stack s2;
};

// stack = last in, first out
// queue = first in, first out

Queue QueueNew(void) {
    Queue q = malloc(sizeof(struct queue));
    q->s1 = StackNew();
    q->s2 = StackNew();
    return q;
}

void QueueEnqueue(Queue q, int item) {
    StackPush(q->s1, item);
}

// assumes that the queue is not empty
int QueueDequeue(Queue q) {
    if (StackSize(q->s2) == 0) {
        while (StackSize(q->s1) != 0) {
            int item = StackPop(q->s1);
            StackPush(q->s2, item);
        }
    }

    return StackPop(q->s2);
}

int QueueSize(Queue q) {
    return StackSize(q->s1) + StackSize(q->s2);
}
