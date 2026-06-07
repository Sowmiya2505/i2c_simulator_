#ifndef FIFO_H
#define FIFO_H

#define FIFO_SIZE 5

typedef struct {
    int q[FIFO_SIZE];
    int front, rear, count;
} FIFO;

void fifo_init(FIFO *f);
void fifo_push(FIFO *f, int data);
int fifo_pop(FIFO *f);

#endif
