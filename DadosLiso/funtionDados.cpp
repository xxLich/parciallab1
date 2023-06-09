#include <iostream>
#include "rlutil.h"
#include "dados.h"
#include <cstdlib> ///Libreria para cambiar el color de fondo

using namespace std;


int main(){

  system ("color 8D");

    dibujarRomano(1,5,5);
    dibujarRomano(2,30,5);
    dibujarRomano(3,55,5);


 /*
  dibujarDado(1,5,5);

  dibujarDado(2,35,5);

  dibujarDado(3,60,5);

  dibujarDado(4,5,20);

  dibujarDado(5,35,20);

  dibujarDado(6,60,20);


   */
   rlutil::locate(1,33);
   system("pause");

return 0;
}




