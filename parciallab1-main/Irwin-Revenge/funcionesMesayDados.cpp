#include <iostream>
#include "mesaydados.h"
#include "rlutil.h"
#include "dado.h"
#include "estructuras.h"

using namespace std;





///DADO DE 10 CARAS
void dado10Caras(int dado)
{
    mesa();
    dibujarDados(dado,55,12);
}

///DOS DADOS DE DIEZ CARAS
void dosDadosDiezCaras(jugadores vJugadores[2],int numeroJugador)
{
    mesa();
    dibujarDados(vJugadores[numeroJugador].dados[0],50,12);
    dibujarDados(vJugadores[numeroJugador].dados[1],60,12);
}
///TRES DADOS DE DIEZ CARAS
void tresDadosDiezCaras(jugadores vJugadores[2],int numeroJugador)
{
    mesa();
    dibujarDados(vJugadores[numeroJugador].dados[0],45,12);
    dibujarDados(vJugadores[numeroJugador].dados[1],55,12);
    dibujarDados(vJugadores[numeroJugador].dados[2],65,12);
}

///CINCO DADOS DE SEIS CARAS
void cincoDadosSeisCaras(jugadores vJugadores[2],int numeroJugador)
{
    mesa();
    dibujarDados(vJugadores[numeroJugador].dados[0],35,12);
    dibujarDados(vJugadores[numeroJugador].dados[1],45,12);
    dibujarDados(vJugadores[numeroJugador].dados[2],55,12);
    dibujarDados(vJugadores[numeroJugador].dados[3],65,12);
    dibujarDados(vJugadores[numeroJugador].dados[4],75,12);
}

void mesa()
{


    int posX =30;
    int posY = 5;
    fondoMesa(posX,posY);
    bordeMesa(posX,posY);

}

///FONDO MESA
void fondoMesa(int posX, int posY)
{
    rlutil::setColor(rlutil::GREEN);
    for(int x=0; x<60; x++)
    {
        for(int y=0; y<18; y++)
        {

            rlutil::locate(x+posX,posY+y);
            cout<<(char)219;

        }


    }

}
///BORDE MESA

void bordeMesa(int posX,int posY)
{
    ///BORDE DE ARRIBA
    rlutil::setColor(rlutil::DARKGREY);
    for(int x=0; x<60; x++)
    {
        rlutil::locate(x+posX,posY);
        cout<<char(219);
    }
    ///BORDE DE ABAJO

    rlutil::setColor(rlutil::DARKGREY);
    for(int x=0; x<60; x++)
    {
        rlutil::locate(x+posX,posY+18);
        cout<<char(219);
    }

    ///BORDE DE DERECHA
    rlutil::setColor(rlutil::DARKGREY);
    for(int y=0; y<19; y++)
    {
        rlutil::locate(posX,y+posY);
        cout<<char(178);
    }

    ///BORDE DE IZQUIERDA

    rlutil::setColor(rlutil::DARKGREY);
    for(int y=0; y<19; y++)
    {
        rlutil::locate(posX+60,y+posY);
        cout<<char(178);


    }

}
