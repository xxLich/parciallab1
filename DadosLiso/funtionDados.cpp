#include <iostream>
#include "rlutil.h"
#include "dados.h"
#include <cstdlib> ///Libreria para cambiar el color de fondo

using namespace std;

int main(){

  system ("color 8D");

  dibujarDado(1,3,5);

  dibujarDado(2,25,5);

  dibujarDado(3,50,5);

  dibujarDado(4,75,5);

  dibujarDado(5,100,5);

  dibujarDado(6,3,20);

  dibujarDado(7,25,20);

  dibujarDado(8,50,20);

  dibujarDado(9,75,20);

  dibujarDado(10,100,20);





   rlutil::locate(1,33);
   system("pause");

return 0;
}



