CC=gcc
CFLAGS=-Wall -ansi -std=c99 -lm

fleschIndex: fleschIndex.o
	$(CC) $(CFLAGS) -o fleschIndex fleschIndex.o
	
fleschIndex.o : fleschIndex.c
	$(CC) $(CFLAGS) -c fleschIndex.c
clean:
	rm fleschIndex fleschIndex.o
