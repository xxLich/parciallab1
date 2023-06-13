#include <iostream>
#include "rlutil.h"
#include "dados.h"
using namespace std;

int main(){

dibujarDados(1,5,5);

dibujarDados(2,15,5);

dibujarDados(3,25,5);

dibujarDados(4,35,5);

dibujarDados(5,45,5);

dibujarDados(6,55,5);

dibujarDados(7,5,10);
dibujarDados(8,15,10);
dibujarDados(9,25,10);
dibujarDados(10,35,10);

rlutil::locate(1,24);

return 0;
}
