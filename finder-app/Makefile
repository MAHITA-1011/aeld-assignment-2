CROSS_COMPILE ?=
CC = $(CROSS_COMPILE)gcc
CFLAGS ?= -Wall -Werror -g

TARGET = writer
OBJS = writer.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
