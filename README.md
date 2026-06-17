# tp-codigo-enigma
TP Topicos de Programacion - Cifrado Cesar (UNLaM 2026)


CASOS DE PRUEBA
====================================
El programa pide UN crib por consola (scanf) y lo busca en los 25 casos
de casosPrueba.h en una sola corrida, escribiendo todos los resultados
en un unico archivo dentro de archivos-descifrados/.

Nota: los caracteres especiales (":", espacio, etc.) no son letras,
no se desplazan, pasan igual del cifrado al descifrado.
El algoritmo reconoce limite de palabra solo con espacio o inicio/fin de texto.


CASOS (crib por defecto: "cita:", salvo donde se indica)
---------------------------------------------------------

--- CASOS FUNCIONALES (crib encontrado) ---

CASO 1 - crib al inicio (desplazamiento 23)
  Cifrado  : flwd: do frplhqcr gho phqvdmh
  Esperado : cita: al comienzo del mensaje

CASO 2 - crib al final (desplazamiento 21)
  Cifrado  : fmtwf af f jxyfw fq knsfq hnyf:
  Esperado : ahora va a estar al final cita:

CASO 3 - crib en el medio (desplazamiento 19)
  Cifrado  : tluzhql jvu jpah: lu ls tlkpv
  Esperado : mensaje con cita: en el medio

CASO 4 - vuelta del alfabeto (desplazamiento 2)
  Cifrado  : agry: uvwx
  Esperado : cita: wxyz
  Nota: la "y" de "agry:" da la vuelta de Z a A al sumarle 2

CASO 5 - largo, crib al inicio (desplazamiento 13, simetrico)
  Cifrado  : pvgn: rfgn rf han cehron ynetn qry pvsenqb prfne
  Esperado : cita: esta es una prueba larga del cifrado cesar

CASO 6 - largo, crib al final (desplazamiento 16)
  Cifrado  : ov woxckto combody peo nocmspbkny qbkmskc k vk msdk:
  Esperado : el mensaje secreto fue descifrado gracias a la cita:

CASO 7 - largo, crib en el medio (desplazamiento 7)
  Cifrado  : xe vhwbzh xgbzft mbxgx ngt vbmt: hvnemt xg xlmx mxqmh vbyktwh
  Esperado : el codigo enigma tiene una cita: oculta en este texto cifrado

CASO 8 - crib DIFERENTE "arbol" (desplazamiento 11)
  Cifrado  : ta ithdgd thip qpyd ta pgqda
  Esperado : el tesoro esta bajo el arbol

CASO 9 - crib al inicio precedido de espacio (desplazamiento 23)
  Cifrado  : [espacio]flwd: do frplhqcr gho phqvdmh
  Esperado : [espacio]cita: al comienzo del mensaje
  Nota: el espacio inicial es reconocido como separador de palabra

CASO 12 - crib al inicio, segunda palabra no cifrada (desplazamiento 2)
  Cifrado  : agry: cita
  Esperado : cita: [texto descifrado]
  Nota: "cita" sin ":" en la segunda palabra no interfiere con el crib "cita:"

CASO 13 - crib literal en shift 0 (desplazamiento 0)
  Cifrado  : cita: rfgn rf han cehron ynetn qry pvsenqb prfne
  Esperado : cita: [resto cifrado, no coincide]
  Nota: el crib ya aparece sin cifrar al inicio del texto

CASO 15 - mayuscula en palabra que NO es el crib (desplazamiento 7)
  Cifrado  : xe vhwbzh xgbzft mbxgx NGT vbmt: hvnemt xg xlmx mxqmh vbyktwh
  Esperado : el codigo enigma tiene una cita: oculta en este texto cifrado
  Nota: "NGT" en mayusculas no produce falso positivo; "vbmt:" sigue siendo hallado

CASO 17 - primeras ocurrencias invalidas, ultima valida (desplazamiento 23)
  Cifrado  : FLWD: flwd flwd : flwd:
  Nota: "FLWD:" en mayusculas y "flwd" sin ":" no coinciden; solo "flwd:" al final

CASO 18 - crib incrustado en palabras mas largas, ultima ocurrencia valida (desplazamiento 23)
  Cifrado  : fflflwflwd: flflwd: flwd:
  Nota: "fflflwflwd:" y "flflwd:" no coinciden por limite de palabra; solo "flwd:" al final

CASO 25 - crib "arbol" exacto entre caracteres especiales (desplazamiento 0)
  Cifrado  : arbol 123123 %%$# /(&/(& 123985 [espacio]
  Esperado : arbol 123123 %%$# /(&/(& 123985 [espacio]
  Nota: crib = arbol encontrado, el resto son caracteres no alfabeticos, quedan igual.

--- CASOS BORDE (crib NO encontrado) ---

CASO 10 - crib entre guiones "-cita:-" (no hay espacio como limite)
  Cifrado  : fmtwf af f jxyfw fq knsfq -hnyf:-
  Resultado: no encontrado
  Motivo   : "-" no es reconocido como separador de palabra

CASO 11 - tabs antes del crib (no hay espacio como limite)
  Cifrado  : tluzhql jvu[TAB][TAB]jpah: lu ls tlkpv
  Resultado: no encontrado
  Motivo   : el TAB no es reconocido como separador de palabra

CASO 14 - crib concatenado con la palabra siguiente sin espacio
  Cifrado  : ov woxckto combody peo nocmspbkny qbkmskc k vk msdk:msdk
  Resultado: no encontrado
  Motivo   : "msdk:msdk" descifra "cita:cita" pero la palabra no termina ahi

CASO 16 - crib "arbol" entre parentesis
  Cifrado  : ta ithdgd thip qpyd ta ( pgqda)
  Resultado: no encontrado
  Motivo   : "(" y ")" no son espacios; "pgqda" no tiene limite de inicio valido

CASO 19 - repeticion de caracteres, una sola palabra larga
  Cifrado  : fffffffflllllwwwdd:
  Resultado: no encontrado
  Motivo   : es una unica palabra sin limite interno; el patron crib no aparece completo

CASO 20 - variantes incorrectas de "arbol"
  Cifrado  : arb-l arbolito arboleda arbbol Arbol abrol arboL arb0l ARBOL
  Resultado: no encontrado (crib "arbol")
  Motivo   : "arb-l" guion; "arbolito/arboleda" palabras mas largas; "Arbol/ARBOL"
             mayusculas; "abrol/arboL" letras incorrectas; "arb0l" digito

CASO 21 - crib seguido de tabulacion (no hay limite de palabra al final)
  Cifrado  : arbol[TAB]
  Resultado: no encontrado (crib "arbol")
  Motivo   : el TAB al final no es reconocido como fin de palabra

CASO 22 - concatenacion de cribs sin espacio entre ellos
  Cifrado  : cita:arbol arbol: cita, cita:arbol
  Resultado: no encontrado
  Motivo   : "cita:arbol" es una sola palabra (no termina en espacio despues del crib);
             "arbol:" tiene algo pegado despues; "cita," termina en coma no en ":"

CASO 23 - cribs con caracteres invalidos intercalados
  Cifrado  : arboL c|ita: marbol $arbol [byte-ext]rbol ^cita:
  Resultado: no encontrado
  Motivo   : ningun crib aparece completo con limites de palabra validos

CASO 24 - solo caracteres especiales y numeros, sin crib
  Cifrado  : arboL 123123 %%$# /(&/(& 123985 [espacio]
  Resultado: no encontrado
  Motivo   : no hay ninguna secuencia que coincida con el crib


COMO PROBAR
-----------
Correr el programa dos veces:

1) Crib: cita:
   Encontrado  -> casos 1(23), 2(21), 3(19), 4(2), 5(13), 6(16), 7(7),
                  9(23), 12(2), 13(0), 15(7), 17(23), 18(23)
   No encontrado -> casos 8, 10, 11, 14, 16, 19, 20, 21, 22, 23, 24, 25

2) Crib: arbol
   Encontrado  -> caso 8(11), caso 25(0)
   No encontrado -> todos los demas


VERIFICACION DE DESPLAZAMIENTOS
-------------------------------------------------------------------------
El cifrado Caesar desplaza cada letra N posiciones hacia adelante.
Para descifrar, el programa aplica el sentido contrario: 26 - N.
Ejemplo: cifrado con N=3 (a->d), se descifra con desplazamiento 23 (d->a).
Caso especial: N=13 es simetrico porque 26 - 13 = 13 (cifrar y descifrar usan el mismo valor).

Caso  1: N de cifrado =  3 -> desplazamiento de descifrado 23
Caso  2: N de cifrado =  5 -> desplazamiento de descifrado 21
Caso  3: N de cifrado =  7 -> desplazamiento de descifrado 19
Caso  4: N de cifrado = 24 -> desplazamiento de descifrado  2
Caso  5: N de cifrado = 13 -> desplazamiento de descifrado 13 (simetrico: 26 - 13 = 13)
Caso  6: N de cifrado = 10 -> desplazamiento de descifrado 16
Caso  7: N de cifrado = 19 -> desplazamiento de descifrado  7
Caso  8: N de cifrado = 15 -> desplazamiento de descifrado 11
Caso  9: igual que caso 1 (mismo cifrado, espacio inicial)
Caso 10: no encontrado (crib entre guiones, sin limite de palabra)
Caso 11: no encontrado (tab antes del crib, no reconocido como separador)
Caso 12: N de cifrado = 24 -> desplazamiento de descifrado  2
Caso 13: N de cifrado =  0 -> desplazamiento de descifrado  0 (texto literal)
Caso 14: no encontrado (crib concatenado con la palabra siguiente)
Caso 15: igual que caso 7 (mismo cifrado, "NGT" en mayusculas)
Caso 16: no encontrado (crib entre parentesis, sin limite de palabra)
Caso 17: N de cifrado =  3 -> desplazamiento de descifrado 23
Caso 18: N de cifrado =  3 -> desplazamiento de descifrado 23
Caso 19: no encontrado (todos los caracteres forman una sola palabra)
Caso 20: no encontrado (variantes incorrectas de "arbol")
Caso 21: no encontrado (tab al final no reconocido como fin de palabra)
Caso 22: no encontrado (crib siempre concatenado sin espacio)
Caso 23: no encontrado (caracteres invalidos interrumpen el crib)
Caso 24: no encontrado (no contiene el crib)
Caso 25: N de cifrado =  0 -> desplazamiento de descifrado  0 (texto literal)


COMO AGREGAR UN CASO DE PRUEBA
-------------------------------
Solo hay que modificar casosPrueba.h. El programa calcula la cantidad de casos
automaticamente con sizeof, no hay ningun contador que actualizar.

Pasos:
1. Abrir casosPrueba.h
2. Agregar una coma al final del ultimo elemento
3. Agregar la nueva cadena cifrada como ultimo elemento
4. Agregar un comentario en la misma linea indicando: numero de caso, crib esperado y shift

Ejemplo: si el ultimo caso es el 25 y se quiere agregar el 26:

    "arbol 123123 %%$# /(&/(& 123985 ",   <- agregar coma aca (era el ultimo)
    "nuevo texto cifrado aqui"             <- nuevo caso 26

5. Actualizar este README: agregar el caso en la seccion de casos y en la tabla
   de verificacion de desplazamientos.


ARCHIVOS HISTORICOS
--------------------
Si el programa se ejecuta mas de una vez dentro del mismo minuto, el archivo
de salida (desencriptado-AAAA-MM-DD-HH-mm.txt) tendria el mismo nombre que el
de la corrida anterior. Para no perder esos resultados, antes de generar el
archivo nuevo el programa renombra el anterior agregandole el prefijo
"historico-v1-" (o "v2-", "v3-", etc. si ya existen versiones anteriores con
ese mismo nombre).
