#include <stdio.h>
#include "fifo.h"

void fifo_init(FIFO *f) {
    f->front = 0;
    f->rear = -1;
    f->count = 0;
}

void fifo_push(FIFO *f, int data) {
    if(f->count == FIFO_SIZE) {
        printf("[FIFO] Overflow\n");
        return;
    }
    f->rear = (f->rear + 1) % FIFO_SIZE;
    f->q[f->rear] = data;
    f->count++;
    printf("[FIFO] Pushed %d\n", data);
}

int fifo_pop(FIFO *f) {
    if(f->count == 0) {
        printf("[FIFO] Underflow\n");
        return -1;
    }
    int val = f->q[f->front];
    f->front = (f->front + 1) % FIFO_SIZE;
    f->count--;
    printf("[FIFO] Popped %d\n", val);
    return val;
}
