#include <stdio.h>

#define STACK_SIZE 5

typedef struct {
    int stack[STACK_SIZE];
    int top;
} LIFO;

void lifo_init(LIFO *s) {
    s->top = -1;
}

void lifo_push(LIFO *s, int data) {
    if(s->top == STACK_SIZE - 1) {
        printf("[LIFO] Overflow\n");
        return;
    }
    s->stack[++s->top] = data;
    printf("[LIFO] Pushed %d\n", data);
}

int lifo_pop(LIFO *s) {
    if(s->top == -1) {
        printf("[LIFO] Underflow\n");
        return -1;
    }
    return s->stack[s->top--];
}
