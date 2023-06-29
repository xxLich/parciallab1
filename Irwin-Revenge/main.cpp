#include <iostream>}
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"
#include <windows.h>
#include "structuras.h"


using namespace std;


const string rutaArchivo = "\Irwin-Revenge";

int main()
{





    int salir = 1;

    /// CURSOR

    int pY = 10,P = 0;


    /// CONSOL TITULO
    rlutil::setConsoleTitle("   Irwin`s Revenge   ");
    rlutil::hidecursor();

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



