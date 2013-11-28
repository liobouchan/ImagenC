#include "netpbm.h"

int main(){
    
//Para guardar lo que lea de la imagen y para nuestros for
  int c1,c2,c3,i,j;
//Aquí va a guardar nuestra imagen y la va a crear
  netpbm im,il,ie,io;
  
//Creamos Las imagenes con sus variables
// im va a ser para mi imagen a cambiar
  netp_crea(&im,300,400,255,C_AZUL);
//il es para guardar todo lo referente a la letra L  
  netp_crea(&il,300,400,255,C_AZUL);
  netp_crea(&ie,300,400,255,C_AZUL);
  netp_crea(&io,300,400,255,C_AZUL);
  
//Cargamos nuestras imagenes 
  netp_load("12.ppm",&im);
  netp_load("L.ppm",&il);
  netp_load("E.ppm",&ie);
  netp_load("O.ppm",&io);

//Tengo que leer mi imagen que tiene la letra y tratar imprimirla aquí

  for(i=0 ; i<il.anc ; i++){
    for(j=0 ; j<il.alt ;j++){
      c1 = il.pix[il.anc*j+i].r;
      rgb_set(im.pix+(im.anc*j+i),c1+1,0,0);
    }
  }
   for(i=0 ; i<ie.anc ; i++){
    for(j=0 ; j<ie.alt ;j++){
     // c1 = il.pix[il.anc*j+i].r;
      c2 = ie.pix[ie.anc*j+i].g;
      //rgb_set(im.pix+(im.anc*j+i),c1+1,0,0);
      rgb_set(im.pix+(im.anc*j+10+i+15),0,c2+1,0);
    }
  } 
   for(i=0 ; i<io.anc ; i++){
    for(j=0 ; j<io.alt ;j++){
     // c1 = il.pix[il.anc*j+i].r;
      c3 = io.pix[io.anc*j+i].b;
      //rgb_set(im.pix+(im.anc*j+i),c1+1,0,0);
      rgb_set(im.pix+(im.anc*j+20+i+40),0,0,c3+1);
    }
  } 
  
  netp_save("uno1.ppm",&im);
  netp_elim(&im);
  return 0;
}
