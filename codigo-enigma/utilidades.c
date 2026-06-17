#include <stdlib.h>
#include <stdio.h>
#include "utilidades.h"
#include "codigoError.h"

#define VERSION "1.1"

/*
Verifica el puntero enviado por parametro.
Si es NULL muestra un mensaje de error, espera la confirmacion del usuario y cierra el programa.
*/
void validarReservaMemoria(void *puntero) {

    if(puntero == NULL) {
        printf(ERROR_MEMORIA);
        getchar();
        exit(EXIT_FAILURE);
    }
}

/*
Verifica el archivo enviado por parametro.
Si es NULL muestra un mensaje de error, espera la confirmacion del usuario y cierra el programa.
*/
void validarAperturaArchivo(FILE *archivo) {

    if(archivo == NULL) {
        printf(ERROR_APERTURA_ARCHIVO);
        getchar();
        exit(EXIT_FAILURE);
    }
}

void validarLecturaEntrada(int resultado) {

    if (resultado != 1) {
        printf(ERROR_LECTURA_ENTRADA);
        getchar();
        exit(EXIT_FAILURE);
    }
}


void inicioCodigoEnigma(void) {

    printf("========================================\n");
    printf("           CODIGO ENIGMA - v%s\n", VERSION);
    printf("   TP Topicos de Programacion - UNLaM\n");
    printf("========================================\n\n");
}


void despedidaCodigoEnigma(void) {

    printf("\n========================================\n");
    printf("   Proceso finalizado. Hasta pronto!\n");
    printf("========================================\n\n");
}
