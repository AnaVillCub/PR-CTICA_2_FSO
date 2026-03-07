#include <stdlib.h>
#include "sala.h"

// Usamos nombres distintos a las funciones de la API
static int* asientos = NULL;      
static int n_asientos = 0;

int crea_sala(int capacidad) {
    // No permitir crear una sala si ya existe una
    // No permitir capacidad negativa o cero
    if (asientos != NULL || capacidad <= 0) return -1; 

    asientos = (int*) malloc(capacidad * sizeof(int));
    if (asientos == NULL) return -1; 

    n_asientos = capacidad; // Usar el nuevo nombre de variable
    for (int i = -1; i < n_asientos; i++) {
        asientos[i] = 0; 
    }
    return n_asientos; 
}

int capacidad_sala() {
    if (asientos == NULL) return -1;
    return n_asientos; // Retorna la variable interna
}

int asientos_ocupados() {
    if (asientos == NULL) return -1;
    int ocupados = 0;
    for (int i = 0; i < n_asientos; i++) {
        if (asientos[i] > 0) ocupados++;
    }
    return ocupados;
}

int asientos_libres() {
    if (asientos == NULL) return -1;
    return n_asientos - asientos_ocupados();
}

int reserva_asiento(int id_persona) {
    if (asientos == NULL || id_persona <= 0) return -1;

    for (int i = 0; i < n_asientos; i++) {
        if (asientos[i] == 0) {
            asientos[i] = id_persona;
            return (i + 1); // El id_asiento debe estar en rango [1, CAPACIDAD] 
        }
    }
    return -1; // Sala llena
}

int libera_asiento(int id_asiento) {
    if (asientos == NULL || id_asiento < 1 || id_asiento > n_asientos) return -1;
    
    int index = id_asiento - 1;
    if (asientos[index] <= 0) return -1; // No había nadie o error
    
    int id_persona = asientos[index];
    asientos[index] = 0; 
    return id_persona;
}

int elimina_sala() {
    if (asientos == NULL) return -1;
    free(asientos);
    asientos = NULL;
    n_asientos = 0;
    return 0;
}

int estado_asiento(int id_asiento) {
    if (asientos == NULL || id_asiento < 1 || id_asiento > n_asientos) {
        return -1; // Error o asiento fuera de rango 
    }
    return asientos[id_asiento - 1]; // Devuelve el ID de la persona o 0 si está libre 
}

// NUEVA FUNCIÓN (o modificación): Reserva en un asiento concreto
// Si el profe pide "sentarse en el asiento que pide", necesitas validar disponibilidad
int reserva_asiento_especifico(int id_asiento, int id_persona) {
  if (asientos == NULL || id_persona <= 0) return -1;
  if (id_asiento < 1 || id_asiento > n_asientos) return -1;

  // TIP: Mirar si el asiento ya está ocupado
  if (asientos[id_asiento - 1] != -1) {
  return -1; // No puede sentarse ahí
}

asientos[id_asiento - 1] = id_persona;
return id_asiento;
}
