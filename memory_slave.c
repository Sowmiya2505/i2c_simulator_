#include <stdio.h>
#include "memory_slave.h"

void mem_init(MemorySlave *m) {
    for(int i = 0; i < MEM_SIZE; i++)
        m->memory[i] = 0;
}

void mem_write(MemorySlave *m, int addr, int data) {
    if(addr >= MEM_SIZE) {
        printf("[MEM] ERROR: Out of range\n");
        return;
    }
    m->memory[addr] = data;
    printf("[MEM] Wrote %d at %d\n", data, addr);
}

int mem_read(MemorySlave *m, int addr) {
    if(addr >= MEM_SIZE) {
        printf("[MEM] ERROR: Invalid read\n");
        return -1;
    }
    return m->memory[addr];
}
