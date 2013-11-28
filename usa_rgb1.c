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
  
//Cargamos nuestras imagenes 
  netp_load("12.ppm",&im);
  netp_load("L.ppm",&il);


    //for(i=0;i < il.anc*il.alt ; ++i){
     //  c1 = il.pix[i].r;
      // c2 = ie.pix[i].g;
      // c3 = io.pix[i].b;

    for (i = 20 ; i < il.anc/**il.alt*/; ++i){
    /*c1 = il.pix[i].r;
    c2 = il.pix[i].g;
    c3 = il.pix[i].b;*/
    //c1 = il.pix[i].r;

    for(j = 20; j < il.alt ; ++j){
      c1 = il.pix[i].r;
      c2 = il.pix[i].g;
       rgb_set(im.pix+(im.anc*j+i),c1,c2,0);
    }

  }

   // }



  //netp_dupl(&im);
  netp_save("uno1.ppm",&im);
  netp_elim(&im);
  return 0;
}
