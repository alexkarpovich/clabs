CC=gcc
CFLAGS=-Wall -std=c99
LDFLAGS=-g -v
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

.PHONY: clean

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)