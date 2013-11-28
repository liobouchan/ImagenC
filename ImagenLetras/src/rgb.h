#ifndef RGB_H
#define RGB_H

#include <stdlib.h>
#include <stdio.h>
/**********************************************************
*        Constantes que definen al manejador de RGB       *
**********************************************************/
#define COLMAX         255  /*Los colores son de 0 a 255*/
#define C_ROJO         1
#define C_BLANCO       2
#define C_AZUL         3
#define C_AMARILLO     4
#define C_ROSA         5
#define C_VERDE        6
#define C_NEGRO        7
#define C_MORADO       8
/**********************************************************
*             Definición de constantes de error           *
/**********************************************************/
#define OK             0
#define E_NOMEM        1     /*Si no hay memoria*/
#define E_APINV        2     /*Si se recibe NULL como 
                               apuntador*/
#define E_PARINV       3     /*Si un parametro con cumple
                               las restricciones*/
#define E_COLINV       4     /*Si un color es mayor */

/**********************************************************
*             Macros                                      *
/**********************************************************/
#define APVAL(x)       ((x)!=NULL)
#define COLVAL(x)      ((x)>=0 && (x)<=COLMAX)

/**********************************************************
*             Definición de tipos de datos                *
/**********************************************************/
typedef struct{
  unsigned char r;      /*cantidad de rojo*/
  unsigned char g;      /*cantidad de verde*/
  unsigned char b;      /*cantidad de azul*/
}rgb;
/**********************************************************
*          Funciones que definen el comportamiento del RGB*
**********************************************************/
/*Asigna un color a un tipo RGB
Recibe: 
  El tipo rgb a ser modificado
  El valor del color rojo, verde y azul
Regresa:
  Código de error en caso de parametros incorrectos
*/
int rgb_set(rgb*,int,int,int);
/*Asigna un color a un tipo RGB
Recibe: 
  El tipo rgb a ser modificado
  Constante que identifica al color
Regresa:
  Código de error en caso de parametros incorrectos
*/
int rgb_setc(rgb*,int);
/*Convierte un código RGB en cadena de caracteres
Recibe: 
  Una cadena que será la salida
  Un valor RGB que será convertido a cadena
Regresa:
  Regresa la misma cadena que recibe pero modificada
*/
char* rgb_str(char*,const rgb*);

/*Verifica si dos colores "se parecen"
Recibe: 
  Dos apuntadores a estructura RGB
  un entero que define la tolerancia de
    diferencia
Regresa:
  1 En caso de estar dentro de la tolerancia
  0 en caso contrario
*/
int rgb_cmp(const rgb*,const rgb*,int);

/*Asigna un color a otro
Recibe: 
  Dos colores RGB
Regresa:
  Código de error en caso de parametros incorrectos
*/
int rgb_asg(rgb* des, const rgb* ori);
#endif
