#include "rgb.h"

/*Verifica si dos colores "se parecen"
Recibe: 
  Dos apuntadores a estructura RGB
  un entero que define la tolerancia de
    diferencia
Regresa:
  1 En caso de estar dentro de la tolerancia
  0 en caso contrario
*/
int rgb_cmp(const rgb* c1,const rgb* c2,int t){
  int res;  
  res = abs(c1->r - c2->r)<t &&
        abs(c1->g - c2->g)<t &&
		abs(c1->b - c2->b)<t;
  return res;
}

/*Asigna un color a un tipo RGB
Recibe: 
  El tipo rgb a ser modificado
  El valor del color rojo, verde y azul
Regresa:
  Código de error en caso de parametros incorrectos
*/
int rgb_set(rgb* c,int r,int g,int b){
  if(!APVAL(c))
    return E_APINV;
  if(!(COLVAL(r)&&COLVAL(g)&&COLVAL(b)))
    return E_COLINV;
  c->r=(unsigned char)r;
  c->g=(unsigned char)g;
  c->b=(unsigned char)b;
  return OK;
}
/*Asigna un color a un tipo RGB
Recibe: 
  El tipo rgb a ser modificado
  Constante que identifica al color
Regresa:
  Código de error en caso de parametros incorrectos
*/
int rgb_setc(rgb* c,int tc){
  if(!APVAL(c))
    return E_APINV;  
  switch (tc) {
    case C_ROJO    : c->r=0xFF; c->g=0x00; c->b=0x00; break;
    case C_BLANCO  : c->r=0xFF; c->g=0xFF; c->b=0xFF; break;
    case C_AZUL    : c->r=0x00; c->g=0x00; c->b=0xFF; break;
    case C_AMARILLO: c->r=0xFF; c->g=0xFF; c->b=0x00; break;
    case C_MORADO  : c->r=0x77; c->g=0x77; c->b=0xFF; break;
    case C_VERDE   : c->r=0x00; c->g=0xFF; c->b=0x00; break;
    case C_NEGRO   : c->r=0x00; c->g=0x00; c->b=0x00; break;
    case C_ROSA    : c->r=0xFF; c->g=0x00; c->b=0x77; break;
  }
  return OK;
}
/*Asigna un color a un tipo RGB
Recibe: 
  El tipo rgb a ser modificado
  El valor del color rojo, verde y azul
Regresa:
  Código de error en caso de parametros incorrectos
*/
char* rgb_str(char* s,const rgb* c){
  if(!(APVAL(s)&&APVAL(c)))
    return s;
  sprintf(s,"%3d %3d %3d ",c->r,c->g,c->b);
  return s;
}

/*Asigna un color a otro
Recibe: 
  Dos colores RGB
Regresa:
  Código de error en caso de parametros incorrectos
*/
int rgb_asg(rgb* des, const rgb* ori){
  if(!(APVAL(des)&&APVAL(ori)))
    return E_APINV;
  des->r = ori->r;
  des->g = ori->g;
  des->b = ori->b;
  return OK;
}

/*Promedia cuatro colores en uno solo
Recibe: 
  Un color destino y cuatro colores a ser promediados
Regresa:
  Código de error en caso de parametros incorrectos
*/
int rgb_prom(rgb* des, const rgb* o1, const rgb* o2, const rgb* o3, const rgb* o4){
  if(!(APVAL(des)&&APVAL(o1)&&APVAL(o2)&&APVAL(o3)&&APVAL(o4)))
    return E_APINV;
  des->r = (o1->r+o2->r+o3->r+o4->r)/4;
  des->g = (o1->g+o2->g+o3->g+o4->g)/4;
  des->b = (o1->b+o2->b+o3->b+o4->b)/4;
  return OK;
}
