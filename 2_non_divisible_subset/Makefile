UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC=gcc
endif
ifeq ($(UNAME_S),Darwin)
	CC=clang
endif

CFLAGS=-Wall -g -O0
LDFLAGS=-g -lm
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