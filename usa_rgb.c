#include "netpbm.h"

int main(){
  netpbm im;
  netp_crea(&im,300,400,255,C_VERDE);
  netp_load("castillo.ppm",&im);
  netp_redu(&im);
  netp_save("uno.ppm",&im);
  netp_elim(&im);
  return 0;
}
