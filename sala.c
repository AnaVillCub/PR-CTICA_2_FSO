#include <stdlib.h>
#include "sala.h"

static int* asientos = NULL;      // Puntero para la memoria dinámica
static int capacidad_sala = 0;    // Para validar límites y errores

int crea_sala(int capacidad) {
    if (asientos != NULL || capacidad <= 0) return -1; // Error si ya existe o capacidad inválida [cite: 178, 185]

    asientos = (int*) malloc(capacidad * sizeof(int)); // Reserva dinámica [cite: 184]
    if (asientos == NULL) return -1; 

    capacidad_sala = capacidad;
    for (int i = 0; i < capacidad; i++) {
        asientos[i] = 0; // Según la tabla, 0 significa libre 
    }
    return capacidad; 
}

int elimina_sala() {
    if (asientos == NULL) return -1; // No se puede eliminar lo que no existe

    free(asientos);
    asientos = NULL;
    capacidad_sala = 0;
    return 0;
}


