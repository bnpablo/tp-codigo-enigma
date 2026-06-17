#ifndef CESAR_H_INCLUDED
#define CESAR_H_INCLUDED

/*
Aplica el desplazamiento inverso a un caracter.
Si no es letra lo devuelve sin cambios.
*/
char descifrarCaracter(char letra, int desplazamiento);

/*
Descifra el texto completo caracter a caracter aplicando el desplazamiento.
Reserva memoria para el resultado. El llamador debe liberar con free().
Retorna una direccion de memoria donde empieza la cadena descifrada.
*/
char* descifrarCompleto(const char *cifrado, int desplazamiento);

/*
Prueba los 26 desplazamientos posibles, descifrando el texto cifrado con
cada uno y buscando el crib en el resultado.
Devuelve el desplazamiento que produce el crib, o -1 si ninguno lo produce.
*/
int encontrarDesplazamiento(const char *textoCifrado, const char *crib);


#endif


