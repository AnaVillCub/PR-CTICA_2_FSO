CC = gcc
CFLAGS = -Wall -g

all: pruebas

pruebas: test_sala.o sala.o
	$(CC) $(CFLAGS) test_sala.o sala.o -o pruebas

sala.o: sala.c sala.h
	$(CC) $(CFLAGS) -c sala.c

test_sala.o: test_sala.c sala.h
	$(CC) $(CFLAGS) -c test_sala.c

clean:
	rm -f *.o pruebas
