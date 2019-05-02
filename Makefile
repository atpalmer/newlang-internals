P=bin/lang
OBJECTS=lang.o type.o integer.o string.o object.o
CC=gcc
CFLAGS=-ggdb -O0

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(P) $(OBJECTS)

.PHONY: clean
clean:
	rm $(P) $(OBJECTS)
