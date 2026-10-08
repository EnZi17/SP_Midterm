CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o ls.o print.o
TARGET = ls

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c ls.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
