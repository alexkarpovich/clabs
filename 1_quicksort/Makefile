CC=gcc
CFLAGS=-Wall -g -O0
LDFLAGS=-g
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

.PHONY: clean

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)