#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"
#include "archivos.h"
#include "cesar.h"
#include "casosPrueba.h"

int main() {

    char crib[21];
    char nombreArchivo[40];
    char *resultado;         /* texto descifrado, reservado dinamicamente por descifrarCompleto() */
    int desplazamiento;      /* 0-25 si se encontro el crib, -1 si no se encontro */
    int i;
    int cantidadCasos;
    FILE *archivoSalida;

    inicioCodigoEnigma();

    /* tamanio total del array (bytes) / tamanio de un elemento (bytes) = cantidad de elementos */
    cantidadCasos = sizeof(casosPrueba) / sizeof(*casosPrueba);

    /* Punto 4: el crib se ingresa por consola, no esta fijo en el codigo */
    printf("Ingrese el crib a buscar (una palabra, SIN ESPACIOS, maximo 20 caracteres): ");
    validarLecturaEntrada(scanf("%20s", crib));

    /* Punto 5: crea/abre el archivo de salida con nombre unico segun fecha y hora */
    archivoSalida = abrirArchivoSalida(nombreArchivo);

    for (i = 0; i < cantidadCasos; i++) {

        /* Puntos 1, 2, 6 y 7: prueba los 26 desplazamientos posibles sobre *(casosPrueba + i)
           y devuelve el desplazamiento que hace que el crib aparezca como palabra completa en
           el texto descifrado, sin importar si esta al inicio, en el medio o al final.
           Si ningun desplazamiento produce el crib, devuelve -1. */
        desplazamiento = encontrarDesplazamiento(*(casosPrueba + i), crib);

        if (desplazamiento == -1) {

            /* No existe ningun desplazamiento que genere el crib en este caso: se registra
            "no encontrado" y se salta directamente a la siguiente iteracion del for,
            sin llamar a descifrarCompleto() (descifrar con -1 generaria caracteres invalidos,
            ej: 'A' - 1 = '@'). */
            escribirResultado(archivoSalida, i + 1, crib, -1, NULL);
            continue;
        }

        /* Puntos 2 y 3: descifra el texto completo con el desplazamiento encontrado. Solo se
        desplazan las letras (A-Z, a-z); los caracteres especiales (espacios, ':', etc.) quedan igual. */
        resultado = descifrarCompleto(*(casosPrueba + i), desplazamiento);

        /* Escribe el resultado (desplazamiento + texto descifrado) en el archivo de salida y tambien
        lo muestra por consola */
        escribirResultado(archivoSalida, i + 1, crib, desplazamiento, resultado);

        free(resultado); /* libera la memoria reservada por descifrarCompleto */
    }

    fclose(archivoSalida);

    despedidaCodigoEnigma();


    return 0;
}
