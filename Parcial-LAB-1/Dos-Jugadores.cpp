#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"



void dosJugadores()
{

    int vectDados[6];

    int salir = 1;

    rlutil::cls();

    do
    {





        rlutil::anykey(" Presione un boton para lanzar ");
         rlutil::cls();


        /// almacena los 6 dados por cada vuelta

        llenarVector(vectDados,6);


        /// dibuja los 6 dados con los valores del vector

        drawSixDados(vectDados);









    }
    while(salir != 0);















}


