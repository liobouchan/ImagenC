#include "netpbm.h"

/*Copia una imágen en otra pero sin crear una imagen nueva*/
int copia(netpbm* des, const netpbm* ori){
  des->anc = ori->anc;
  des->alt = ori->alt;
  des->numcol = ori->numcol;
  des->pix = ori->pix;
}

/* Amplia una imagen al doble de su tamaño
*/
int netp_dupl(netpbm* im){
  int i,j;
  netpbm im_aux;
  if(!IMVAL(im))
    return E_APINV;
  if(!netp_crea(&im_aux,2*im->anc,2*im->alt,im->numcol,C_VERDE)==OK)
    return E_NOMEM;
  for(i=0;i<im->alt;i++)
    for(j=0;j<im->anc;j++){
	  rgb_asg(&GET_P(&im_aux,2*i,2*j)    ,&GET_P(im,i,j));
	  rgb_asg(&GET_P(&im_aux,2*i,2*j+1)  ,&GET_P(im,i,j));
	  rgb_asg(&GET_P(&im_aux,2*i+1,2*j)  ,&GET_P(im,i,j));
	  rgb_asg(&GET_P(&im_aux,2*i+1,2*j+1),&GET_P(im,i,j));
	}
  netp_elim(im);
  copia(im,&im_aux);
  return OK;
}

/* Amplia una imagen al doble de su tamaño
*/
int netp_redu(netpbm* im){
  int i,j;
  netpbm im_aux;
  if(!IMVAL(im))
    return E_APINV;
  if(!netp_crea(&im_aux,im->anc/2,im->alt/2,im->numcol,C_VERDE)==OK)
    return E_NOMEM;
  for(i=0;i<im->alt;i++)
    for(j=0;j<im->anc;j++)
	  if( i%2==0 && j%2==0)
	    rgb_prom(&GET_P(&im_aux,i/2,j/2),
		         &GET_P(im,i,j),  &GET_P(im,i,j+1),
	             &GET_P(im,i+1,j),&GET_P(im,i+1,j+1));
  netp_elim(im);
  copia(im,&im_aux);
  return OK;
}

/* Crea una imagen con un fondo fijo
*/
int netp_crea(netpbm* im,int an ,int al, int nc ,int c){
  int i;
  if(!APVAL(im))
    return E_APINV;
  if(!(an>0 && al >0))
    return E_PARINV;
  /*Evita que el color este fuera de rango*/
  c %= C_MORADO;
  im->pix = (rgb*)malloc(sizeof(rgb)*an*al);
  if(!APVAL(im->pix))
    return E_APINV;
  im->anc = an;
  im->alt = al;
  im->numcol = nc;
  for(i=0;i<an*al;i++)
    rgb_setc(im->pix+i,c);
  return OK;
}
/* Elimina la imagen y regresa la memoria dinámica
*/
int netp_elim(netpbm* im){
  if(!APVAL(im))
    return E_APINV;
  if(im->pix)
    free(im->pix);
  im->anc = 0;
  im->alt = 0;
  return OK;
}

int netp_load(char* nom, netpbm* im){
  FILE* archivo;
  char linea[TAMCAD];
  int i,r,g,b,an,al,numcol;
  if(!(APVAL(im)&&APVAL(nom)))
    return E_APINV;
  archivo = fopen(nom,"r");
  if(!APVAL(archivo))
    return E_ARCINV;
  fscanf(archivo,"%s",linea);
  if(strcmp(linea,P3)!=0){
    fclose(archivo);
    return E_FORINV;
  }
  do{ /*Omite los comentarios*/
    fgets(linea,TAMCAD,archivo);
  }while(*linea=='#' || *linea=='\n');
  sscanf(linea,"%d%d",&an,&al);
  fscanf(archivo,"%d",&numcol);
  netp_elim(im);
  if(netp_crea(im,an,al,numcol,C_BLANCO)!=OK)
    return E_NOMEM;
  for(i=0;i<im->anc*im->alt;i++){
    fscanf(archivo,"%d%d%d",&r,&g,&b);
	rgb_set(im->pix+i,r,g,b);
  }
  fclose(archivo);
  return OK;
}

/*Almacena una imágen en un archivo.
*/
int netp_save(char* nom, const netpbm* im){
  FILE* archivo;
  char salida[TAMCAD];
  int i;
  if(!(APVAL(im)&&APVAL(nom)))
    return E_APINV;
  if(!IMVAL(im))
    return E_IMAINV;
  archivo = fopen(nom,"w");
  if(!APVAL(archivo))
    return E_ARCINV;
  fprintf(archivo,"%s\n",P3);
  fprintf(archivo,"%d %d\n",im->anc,im->alt);
  fprintf(archivo,"%d\n",im->numcol);
  for(i=0;i<im->alt*im->anc;i++)
    fprintf(archivo,"%s",rgb_str(salida,im->pix+i));
  fclose(archivo);
  return OK;
}
