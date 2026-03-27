CC = gcc
SRC_DIR = src
TARGET = task4
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(notdir $(SOURCES:%.c=%.o))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

clean:
	rm -f $(TARGET) *.o data.txt results.txt

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
