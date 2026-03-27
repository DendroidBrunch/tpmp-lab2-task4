CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = person_processor
OBJS = main.o file_io.o person.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c person.h file_io.h
	$(CC) $(CFLAGS) -c main.c

file_io.o: file_io.c file_io.h person.h
	$(CC) $(CFLAGS) -c file_io.c

person.o: person.c person.h
	$(CC) $(CFLAGS) -c person.c

clean:
	rm -f $(TARGET) $(OBJS) data.txt results.txt

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
