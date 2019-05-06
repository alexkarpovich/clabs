CC=clang
CFLAGS=-Wall -g -O0
LDFLAGS=-g
SOURCES=main.c qsort.c qsort_template.c
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