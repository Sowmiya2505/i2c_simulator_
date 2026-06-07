#include <stdio.h>
#include "memory_slave.h"
#include "fifo.h"

int main() {
    MemorySlave mem;
    FIFO fifo;

    mem_init(&mem);
    fifo_init(&fifo);

    int choice, addr, data;

    while(1) {
        printf("\n--- I2C SIMULATOR ---\n");
        printf("1. Memory Write\n");
        printf("2. Memory Read\n");
        printf("3. FIFO Push\n");
        printf("4. FIFO Pop\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter addr data: ");
                scanf("%d %d", &addr, &data);
                mem_write(&mem, addr, data);
                break;

            case 2:
                printf("Enter addr: ");
                scanf("%d", &addr);
                printf("Value = %d\n", mem_read(&mem, addr));
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                fifo_push(&fifo, data);
                break;

            case 4:
                fifo_pop(&fifo);
                break;

            case 5:
                return 0;
        }
    }
}
