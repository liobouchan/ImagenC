#ifndef NETPBM_H
#define NETPBM_H
#include <stdio.h>
#include "rgb.h"
/***********************************************************
*             Definici�n de constantes                     *
/**********************************************************/
/*Formatos permitidos*/
#define P1                  "P1"
#define P2                  "P2"
#define P3                  "P3"
#define P4                  "P4"
#define P5                  "P5"
#define P6                  "P6"
#define TAMCAD              200 /*Tama�o cadena auxiliar*/
/***********************************************************
*             Define los posibles errores                  *
/**********************************************************/
#define E_IMAINV              100
#define E_ARCINV              101
#define E_FORINV              102
/***********************************************************
*             Macros                                       *
/**********************************************************/
/*Imagen que ha sido crerada*/
#define IMVAL(x)       ((x)!=NULL && (x)->pix!=NULL)
/*Obenet un pixel de una imagen dada*/
#define GET_P(x,i,j)   ( *((x)->pix+(i)*(x)->anc+(j)) )
/***********************************************************
*             Definici�n de tipos de datos                 *
/**********************************************************/
typedef struct{
  int anc;     /*Ancho de la imagen*/
  int alt;     /*Alto de la imagen*/
  int numcol;  /*rango m�ximo de color 0 a 255*/
  rgb* pix;    /*Arreglo de pixeles*/
}netpbm;

/**********************************************************
*    Funciones que Manejan del archivos en formato P3     *
**********************************************************/
/*Asigna memoria din�mica dependiendo del tama�o recibido
  Inicializa el fondo de la imagen con un colof fijo
Recibe: 
  Estructura para crear la imagen
  Tama�o de la imagen a ser creada
  Numero que representa al color m�s intenso
  Color del fondo de la imagen
Regresa:
  C�digo de error en caso de parametros incorrectos
*/
int netp_crea(netpbm*,int,int,int,int);
/*Elimina la imagen, regresa la memoria dinamica y coloca
  todos los campos de la imagen a cero
Recibe:
  apuntador a imagen a ser eliminada
Regresa:
  C�digo de error en caso de recibir cero
*/
int netp_elim(netpbm*);

/*Almacena una im�gen en un archivo.
Recibe:
  Nombre del archivo.
  Apuntador a imagen a ser almacenada.
Regresa
  C�digo de error*/
int netp_save(char* nom, const netpbm* im);

/*Carga una im�gen desde un archivo que tiene
  el formato P3
Recibe:
  Nombre del archivo.
  Apuntador a la imagen a ser cargada.
Regresa:
  C�digo de error.
*/
int netp_load(char* nom, netpbm* im);

/*Duplica el tama�o de una imagen. Para ello
  convierte un pixel en cuadro. Elimina la imagen
  original y crea una nueva.
Recibe:
  Estructura de la imagen a ser convertida
Regresa:
  C�digo de error.
*/
int netp_dupl(netpbm* im);

/*Reduce una imagen a la mitad de su tama�o.
  En caso de ser imar tendr� un pixel menos
Recibe:
  Estructura de la imagen a ser convertida
Regresa:
  C�digo de error.
*/
int netp_redu(netpbm* im);
#endif
