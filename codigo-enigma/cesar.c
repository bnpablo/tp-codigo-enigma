#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cesar.h"
#include "utilidades.h"


/*
Descifra el texto completo caracter a caracter aplicando el desplazamiento.
Reserva memoria para el resultado. El llamador debe liberar con free().
Retorna una direccion de memoria donde empieza la cadena descifrada.
*/

char* descifrarCompleto(const char *textoCifrado, int desplazamiento) {

    char *textoDescifrado;
    int i;

    /* Reserva el bloque de memoria para guardar el resultado +1 para el '\0' */
    textoDescifrado = (char*) malloc(strlen(textoCifrado) + 1);
    validarReservaMemoria(textoDescifrado);

    i = 0;

    while (*(textoCifrado + i) != '\0') {

        *(textoDescifrado  + i) = descifrarCaracter(*(textoCifrado + i), desplazamiento);

        i++;
    }

    *(textoDescifrado + i) = '\0';

    return textoDescifrado;
}


/*
Prueba los 26 desplazamientos posibles. Para cada uno recorre el texto
cifrado descifrando caracter a caracter y comparando contra el crib,
respetando los limites de palabra (espacios o inicio/fin de texto).
Devuelve el desplazamiento que produce el crib, o -1 si ninguno lo produce.
*/
int encontrarDesplazamiento(const char *textoCifrado, const char *crib) {

    int desplazamiento;
    int i; /* recorre el texto cifrado */
    int j; /* recorre el crib */
    int tamCrib;

    tamCrib = strlen(crib);

    for(desplazamiento = 0; desplazamiento < 26; desplazamiento++) {

        i = 0;
        j = 0;

        while(*(textoCifrado + i) != '\0') {

            if(*(textoCifrado + i) == ' ') { /* nueva palabra: reinicia el contador */
                j = 0;
                i++;
                continue; /* <- vuelve a chequear *(textoCifrado+i) != '\0' */
            }

            /* descifra y compara; solo cuenta si arranca palabra o ya veniamos matcheando */
            if(descifrarCaracter(*(textoCifrado + i), desplazamiento) == *(crib + j)
                    && (j != 0 || i == 0 || *(textoCifrado + i - 1) == ' ')) {

                j++;

                if(j == tamCrib) {
                    if(*(textoCifrado + i + 1) == ' ' || *(textoCifrado + i + 1) == '\0') {
                        return desplazamiento; /* coincide y la palabra termina aca */
                    }
                    j = 0; /* la palabra sigue, era mas larga que el crib */
                }
            } else {
                j = 0;
            }

            i++;
        }
    }

    return -1;
}


/*
Aplica el desplazamiento a un caracter (descifrado Cesar).
Si no es una letra, lo devuelve sin cambios.
*/
char descifrarCaracter(char caracter, int desplazamiento) {

    char base;

    base = caracter;

    if( isalpha(caracter)==0 ) {

        return caracter;

    } else {

        /* Se usa mayuscula dado que A-Z y a-z tienen el mismo limite, 26 letras */
        base = toupper(base) + desplazamiento;

        /* Si se pasa de 'Z': vuelve a empezar desde 'A' */
        if( base>'Z' )
            caracter = caracter + desplazamiento - 26;
        else
            caracter += desplazamiento;
    }
    return caracter;
}
