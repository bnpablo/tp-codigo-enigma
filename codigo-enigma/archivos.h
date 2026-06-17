#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdio.h>

FILE* abrirArchivoSalida(char *nombreArchivo);

/*
Escribe el texto descifrado y el desplazamiento en el archivo de salida.
*/
void escribirResultado(FILE *archivo, int numeroCaso, const char *crib, int desplazamiento, const char *textoDescifrado);

/*
Genera el nombre del archivo de salida con el timestamp actual.
Formato: desencriptado-YYYY-MM-DD-HH-mm.txt
*/
void generarNombreArchivo(char *nombre);

#endif
