#ifndef MEMORY_SLAVE_H
#define MEMORY_SLAVE_H

#define MEM_SIZE 64

typedef struct {
    int memory[MEM_SIZE];
} MemorySlave;

void mem_init(MemorySlave *m);
void mem_write(MemorySlave *m, int addr, int data);
int mem_read(MemorySlave *m, int addr);

#endif
