#include <iostream>}
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"
#include <windows.h>
#include "reglas.h"


using namespace std;




int main()
{


    int salir = 1;

    /// CURSOR

    int pY = 10,P = 0;


    /// CONSOL TITULO
    rlutil::setConsoleTitle("   Irwin`s Revenge   ");
    rlutil::hidecursor();


    /// intro

    Bienvenida(30,5);

    rlutil::anykey();

    rlutil::cls();

    regla1(30,10);

    rlutil::anykey();
     rlutil::cls();


    regla2(30,10);

    rlutil::anykey();

    rlutil::cls();


    do
    {

        /// Dibuja el menu estatico por defecto

        drawMenu(P);


        /// seleccionar accion

        selectOpciones(P,pY,salir);

    }
    while(salir != 0);

    return 0;
}



