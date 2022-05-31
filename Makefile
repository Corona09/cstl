SOURCES := $(wildcard ./*.c)
OBJECTS := $(patsubst ./%.c, %.o, $(SOURCES))
CC = gcc
CFLAGS += -std=c11 -g -DDEBUG

all: $(OBJECTS)
	# $(CC) $^ $(CFLAGS) -o $@

%.o: %.c
	$(CC) -c $^ $(CFLAGS) -o $@

install: all

clean:
	$(RM) *.o *.exe

uninstall: clean
	$(RM) *.exe
