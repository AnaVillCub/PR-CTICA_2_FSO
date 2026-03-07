// test_sala.c
#include <assert.h>
#include <stdio.h>
#include "sala.h"  // <--- ESTA LÍNEA ES IMPRESCINDIBLE

#define DebeSerCierto(x)	assert(x)
#define DebeSerFalso(x)		assert(!(x))

void INICIO_TEST (const char* titulo_test)
{
  printf("********** batería de pruebas para %s: ", titulo_test); 
 	// fflush fuerza que se imprima el mensaje anterior
	// sin necesidad de utilizar un salto de línea
	fflush(stdout);
}

void FIN_TEST (const char* titulo_test)
{
  printf ("********** hecho\n");
}


void test_ReservaBasica()
{
	int mi_asiento;
	#define CAPACIDAD 500
	#define ID_1 1500

	INICIO_TEST("Reserva básica");
	crea_sala(CAPACIDAD);
	DebeSerCierto(capacidad_sala()==CAPACIDAD);
	DebeSerCierto((mi_asiento=reserva_asiento(ID_1))>=0);
	DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD);
	DebeSerCierto(estado_asiento(mi_asiento)>0);
	DebeSerCierto(libera_asiento(mi_asiento)==ID_1);
	DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD);
	elimina_sala();
	FIN_TEST("Reserva básica");
}


void ejecuta_tests ()
{
	test_ReservaBasica();
	// Añadir nuevos tests 
}

int main() // <--- Añade 'int'
{
	puts("Iniciando tests...");
	ejecuta_tests();
	puts("Batería de test completa.");
    return 0; // <--- Añade el retorno
}

void test_TipsProfesor() {
INICIO_TEST("Tips del Profesor (Robustez)");

// 1. Intentar crear sala con capacidad negativa
DebeSerCierto(crea_sala(-10) == -1);

// 2. Crear sala legal
crea_sala(10);

// 3. Intentar crear OTRA sala sin borrar la anterior
DebeSerCierto(crea_sala(5) == -1);

// 4. Intentar reservar asiento con ID de persona inválido (negativo)
DebeSerCierto(reserva_asiento(-5) == -1);

// 5. Intentar liberar un asiento que no existe (ej. asiento 999)
DebeSerCierto(libera_asiento(999) == -1);

// 6. Test de ocupación: Sentar a alguien y que otro no pueda quitarle el sitio
reserva_asiento(100); // Se sienta en el 1
// Si implementaste reserva_asiento_especifico:
// DebeSerCierto(reserva_asiento_especifico(1, 200) == -1);

elimina_sala();
FIN_TEST("Tips del Profesor");
}
