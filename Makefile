# Variables para facilitar cambios futuros
CC = gcc
CFLAGS = -Wall -g
OBJ = sala.o test_sala.o

# Regla principal: lo que se ejecuta al escribir solo 'make'
all: pruebas

# Crear el ejecutable final enlazando los objetos
pruebas: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o pruebas

# Compilar sala.c para generar el objeto sala.o
# Depende de sala.c y sala.h; si uno cambia, se recompila
sala.o: sala.c sala.h
	$(CC) $(CFLAGS) -c sala.c

# Compilar test_sala.c para generar el objeto test_sala.o
test_sala.o: test_sala.c sala.h
	$(CC) $(CFLAGS) -c test_sala.c

# Regla para limpiar archivos temporales y el ejecutable
clean:
	rm -f $(OBJ) pruebas
