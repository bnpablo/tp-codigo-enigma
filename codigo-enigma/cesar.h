#ifndef CESAR_H_INCLUDED
#define CESAR_H_INCLUDED


char descifrarCaracter(char letra, int desplazamiento);
void descifrarCompleto(const char *texto, int desplazamiento, char *resultado);
int encontrarDesplazamiento(const char *textoCifrado, const char *crib);


#endif // CESAR_H_INCLUDED



