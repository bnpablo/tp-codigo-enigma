#ifndef CASOSPRUEBA_H_INCLUDED
#define CASOSPRUEBA_H_INCLUDED


/* Cifrados de prueba. Crib esperado: "cita:" salvo donde se indique.

No es un array de strings, es un array de punteros.
Solo guarda las direcciones donde empieza cada uno.
Con static, cada .c que incluye el header se queda con su propia copia privada de casosPrueba,
sin chocar con la de otro archivo al compilar.
*/
static const char *casosPrueba[] = {
    "flwd: do frplhqcr gho phqvdmh",                                 /* 1: crib = "cita:" al inicio, shift 23 */
    "fmtwf af f jxyfw fq knsfq hnyf:",                               /* 2: crib = "cita:" al final, shift 21 */
    "tluzhql jvu jpah: lu ls tlkpv",                                 /* 3: crib = "cita:" en el medio, shift 19 */
    "agry: uvwx",                                                    /* 4: shift 2, "y" da la vuelta del alfabeto y la x no -> "cita: wxyz" */
    "pvgn: rfgn rf han cehron ynetn qry pvsenqb prfne",              /* 5: largo, crib = "cita:" al inicio, shift 13 */
    "ov woxckto combody peo nocmspbkny qbkmskc k vk msdk:",          /* 6: largo, crib = "cita:" al final, shift 16 */
    "xe vhwbzh xgbzft mbxgx ngt vbmt: hvnemt xg xlmx mxqmh vbyktwh", /* 7: largo, crib = "cita:" en el medio, shift 7 */
    "ta ithdgd thip qpyd ta pgqda",                                  /* 8: crib DIFERENTE = "arbol" -> "el tesoro esta bajo el arbol" */
    " flwd: do frplhqcr gho phqvdmh",                                /* 9: crib al inicio luego de un espacio, shift 23 */
    "fmtwf af f jxyfw fq knsfq -hnyf:-",                             /* 10: crib entre "-" al final, shift 21 */
    "tluzhql jvu\t\tjpah: lu ls tlkpv",                              /* 11: crib en el medio con espacio + dos tabs antes, shift 19 */
    "agry: cita",                                                    /* 12: shift 2, crib "cita:" al inicio */
    "cita: rfgn rf han cehron ynetn qry pvsenqb prfne",              /* 13: largo, crib literal en shift 0, resto incomprensible */
    "ov woxckto combody peo nocmspbkny qbkmskc k vk msdk:msdk",      /* 14: largo, crib pegado a otra palabra */
    "xe vhwbzh xgbzft mbxgx NGT vbmt: hvnemt xg xlmx mxqmh vbyktwh", /* 15: largo, mayuscula en otra palabra (no en el crib) */
    "ta ithdgd thip qpyd ta ( pgqda)",                               /* 16: crib "arbol" entre parentesis */
    "FLWD: flwd flwd : flwd:",                                       /* 17: malos ingresos del crib menos el ultimo */
    "fflflwflwd: flflwd: flwd:",                                     /* 18: idem anterior pero con el crib incrustado en palabras */
    "fffffffflllllwwwdd:",                                           /* 19: repeticion de caracteres, no esta el crib */
    "arb-l arbolito arboleda arbbol Arbol abrol arboL arb0l ARBOL",  /* 20: incorrectos ingresos de "arbol" */
    "arbol\t",                                                       /* 21: crib + tabulacion */
    "cita:arbol arbol: cita, cita:arbol",                            /* 22: concatenacion de "cribs" */
    "arboL c|ita: marbol $arbol \xc3\xa2rbol ^cita:",                /* 23: incorrectos ingresos de "cribs" */
    "arboL 123123 %%$# /(&/(& 123985 ",                              /* 24: caracteres sin crib */
    "arbol 123123 %%$# /(&/(& 123985 ",                               /* 25: caracteres con crib */



};


#endif
