#include <stdio.h>
#include "i2c_bus.h"

void init_bus(I2C_Bus *bus) {
    bus->count = 0;
    bus->bus_busy = 0;
}

void register_device(I2C_Bus *bus, I2C_Device dev) {
    bus->devices[bus->count++] = dev;
}

I2C_Device* find_device(I2C_Bus *bus, int address) {
    for(int i = 0; i < bus->count; i++) {
        if(bus->devices[i].address == address)
            return &bus->devices[i];
    }
    return NULL;
}

void start_condition() {
    printf("[I2C] START condition\n");
}

void stop_condition() {
    printf("[I2C] STOP condition\n");
}

void log_bus(const char *msg) {
    printf("[BUS] %s\n", msg);
}
