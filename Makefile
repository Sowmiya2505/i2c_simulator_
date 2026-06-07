all:
	gcc main.c memory_slave.c fifo.c i2c_bus.c lifo.c -o i2c_sim

clean:
	rm -f i2c_sim
