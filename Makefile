TARGET=shuffle_experiment

CC=gcc
CFLAGS = -std=c11
LFLAGS = -std=c11

OBJECTS=shuffle_experiment.o

$(TARGET): $(OBJECTS)
	$(CC) $< -o $@ $(LFLAGS)

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm $(TARGET) $(TARGET).exe.stackdump data.csv options.csv