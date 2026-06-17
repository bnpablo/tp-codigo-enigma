#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include <stdio.h>

/*
Verifica el puntero enviado por parametro.
Si es NULL muestra un mensaje de error, espera la confirmacion del usuario y cierra el programa.
*/
void validarReservaMemoria(void *puntero);

/*
Verifica el archivo enviado por parametro.
Si es NULL muestra un mensaje de error, espera la confirmacion del usuario y cierra el programa.
*/
void validarAperturaArchivo(FILE *archivo);

/*
Verifica que scanf() haya leido correctamente el dato esperado.
*/
void validarLecturaEntrada(int resultado);

void inicioCodigoEnigma(void);

void despedidaCodigoEnigma(void);



#endif
