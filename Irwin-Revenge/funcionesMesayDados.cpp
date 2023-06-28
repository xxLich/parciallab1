#include <iostream>
#include "mesaydados.h"
#include "rlutil.h"
#include "dado.h"
using namespace std;






///DADO DE 10 CARAS
void dado10Caras(int posX,int posY,int dado){
    mesa(posX, posY);
    dibujarDados(dado,55,12);
}

///DOS DADOS DE SEIS CARAS
void dosDadosSeisCaras(int posX,int posY,int dadoUno,int dadoDos){

    mesa(posX, posY);
    dibujarDados(dadoUno,50,12);
    dibujarDados(dadoDos,60,12);
}
///TRES DADOS DE SEIS CARAS
void tresDadosSeisCaras(int posX,int posY,int dado){
    mesa(posX, posY);
    dibujarDados(dado,45,12);
    dibujarDados(dado,55,12);
    dibujarDados(dado,65,12);
}

///CINCO DADOS DE SEIS CARAS
void cincoDadosSeisCaras(int posX,int posY,int dado){
    mesa(posX, posY);
    dibujarDados(dado,35,12);
    dibujarDados(dado,45,12);
    dibujarDados(dado,55,12);
    dibujarDados(dado,65,12);
    dibujarDados(dado,75,12);
}

void mesa(int posX, int posY){



    fondoMesa(posX,posY);
    bordeMesa(posX,posY);

}

///FONDO MESA
void fondoMesa(int posX, int posY){
    rlutil::setColor(rlutil::GREEN);
    for(int x=0;x<60;x++){
        for(int y=0;y<18;y++){

            rlutil::locate(x+posX,posY+y);
            cout<<(char)219;

        }


    }

}
///BORDE MESA

void bordeMesa(int posX,int posY){
    ///BORDE DE ARRIBA
    rlutil::setColor(rlutil::DARKGREY);
    for(int x=0;x<60;x++){
        rlutil::locate(x+posX,posY);
        cout<<char(219);
    }
     ///BORDE DE ABAJO

      rlutil::setColor(rlutil::DARKGREY);
    for(int x=0;x<60;x++){
        rlutil::locate(x+posX,posY+18);
        cout<<char(219);
    }

        ///BORDE DE DERECHA
        rlutil::setColor(rlutil::DARKGREY);
        for(int y=0;y<19;y++){
            rlutil::locate(posX,y+posY);
             cout<<char(178);
        }

        ///BORDE DE IZQUIERDA

        rlutil::setColor(rlutil::DARKGREY);
        for(int y=0;y<19;y++){
            rlutil::locate(posX+60,y+posY);
            cout<<char(178);


        }

}
