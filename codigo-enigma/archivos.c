#include <stdio.h>
#include <time.h>
#include "archivos.h"
#include "utilidades.h"

#define CARPETA_SALIDA "../archivos-descifrados/"

static int archivoExiste(const char *ruta);
static void archivarSiExiste(const char *ruta, const char *nombreArchivo);

/*
Abre (crea) el archivo de salida en modo escritura y devuelve su FILE*
para que main() escriba ahi los resultados de cada caso.
Para armar la ruta, llama a generarNombreArchivo() y lo concatena
con la carpeta de salida (CARPETA_SALIDA).
*/
FILE* abrirArchivoSalida(char *nombreArchivo) {
    char ruta[65]; /* ruta completa: carpeta de salida + nombre de archivo */
    FILE *archivo;

    generarNombreArchivo(nombreArchivo);

    sprintf(ruta, "%s%s", CARPETA_SALIDA, nombreArchivo); /* concatena carpeta + nombre y lo guarda en ruta */

    archivarSiExiste(ruta, nombreArchivo);

    archivo = fopen(ruta, "w"); /* crea/abre el archivo en modo escritura */
    validarAperturaArchivo(archivo);

    printf("\nArchivo generado: %s\n\n", ruta);

    return archivo; /* main() usa este puntero para ir escribiendo cada caso */
}


/*
Escribe el resultado del caso tanto en el archivo de salida como por consola (log).
Si desplazamiento == -1, el crib no fue encontrado en ningun desplazamiento
y solo se informa ese hecho.
*/
void escribirResultado(FILE *archivo, int numeroCaso, const char *crib, int desplazamiento, const char *textoDescifrado) {

    if (desplazamiento == -1) {

        /* No se encontro un desplazamiento que produzca el crib esperado */
        fprintf(archivo, "Caso %d: \n crib: \"%s\" --> no encontrado.\n\n", numeroCaso, crib);
        printf("Caso %d -> Desplazamiento: no encontrado. | Crib ingresado: \"%s\" \n\n", numeroCaso, crib);
        return;
    }

    /* Detalle completo en el archivo */
    fprintf(archivo, "Caso %d:\n", numeroCaso);
    fprintf(archivo, "  Desplazamiento: %d\n", desplazamiento);
    fprintf(archivo, "  Texto descifrado: %s\n\n", textoDescifrado);

    /* Resumen en consola para seguimiento en tiempo real */
    printf("Caso %d -> Desplazamiento: %02d | Texto descifrado --> %s\n\n", numeroCaso, desplazamiento, textoDescifrado);
}

/*
Indica si ya existe un archivo en la ruta indicada.
Se usa fopen en modo lectura como test de existencia.
Si existe, se cierra antes de devolver.
*/
static int archivoExiste(const char *ruta) {
    FILE *archivo;

    archivo = fopen(ruta, "r");

    if (archivo == NULL) {
        return 0;
    }

    fclose(archivo);
    return 1;
}

/*
Si ya existe un archivo en 'ruta' (de una ejecucion anterior en el mismo minuto),
lo renombra como "historico-vN-<nombreArchivo>" (N = primer numero libre),
para no perder su contenido antes de que 'ruta' se sobreescriba.
*/
static void archivarSiExiste(const char *ruta, const char *nombreArchivo) {
    char rutaHistorico[80]; /* carpeta + "historico-vN-" + nombre de archivo */
    int version;

    /* Si no hay nada que archivar, corta aca y vuelve al que la llamo */
    if (!archivoExiste(ruta)) {
        return;
    }

    version = 1;
    sprintf(rutaHistorico, "%shistorico-v%d-%s", CARPETA_SALIDA, version, nombreArchivo);

    while (archivoExiste(rutaHistorico)) {
        version++;
        sprintf(rutaHistorico, "%shistorico-v%d-%s", CARPETA_SALIDA, version, nombreArchivo);
    }

    rename(ruta, rutaHistorico);
}


/*
Genera el nombre del archivo de salida usando la fecha y hora actual,
y lo guarda en 'nombre' (el llamador reserva el espacio).
*/

void generarNombreArchivo(char *nombre) {
    time_t tiempo_actual;

    struct tm *info_tiempo;

    tiempo_actual = time(NULL);
    info_tiempo = localtime(&tiempo_actual);

    sprintf(nombre, "desencriptado-%d-%02d-%02d-%02d-%02d.txt",
            info_tiempo->tm_year + 1900,  /* El anio arranca en 1900*/
            info_tiempo->tm_mon + 1,      /* Los meses van de 0 a 11*/
            info_tiempo->tm_mday,         /* Dia del mes*/
            info_tiempo->tm_hour,         /* Hora*/
            info_tiempo->tm_min);         /* Minutos*/
}
