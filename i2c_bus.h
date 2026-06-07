#ifndef I2C_BUS_H
#define I2C_BUS_H

#define MAX_DEVICES 10

typedef enum {
    SLAVE_MEMORY,
    SLAVE_FIFO,
    SLAVE_LIFO
} DeviceType;

typedef struct {
    int address;
    DeviceType type;
    void *device;
} I2C_Device;

typedef struct {
    I2C_Device devices[MAX_DEVICES];
    int count;
    int bus_busy;
} I2C_Bus;

void init_bus(I2C_Bus *bus);
void register_device(I2C_Bus *bus, I2C_Device dev);
I2C_Device* find_device(I2C_Bus *bus, int address);

void start_condition();
void stop_condition();
void log_bus(const char *msg);

#endif
