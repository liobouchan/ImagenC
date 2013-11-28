#include "netpbm.h"

int main(){

  int c1, c2, c3,i,c4,c5,c6,j;
  netpbm im,il,ie,io;
  netp_crea(&im,300,400,255,C_AZUL);
  netp_load("12.ppm",&im);

  //La letra L
  netp_crea(&il,300,400,255,C_AZUL);
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
