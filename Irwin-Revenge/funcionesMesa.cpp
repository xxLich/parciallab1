#include <iostream>
#include "mesa.h"
#include "rlutil.h"
#include "dado.h"
using namespace std;


void dibujarMesa(int posX,int posY,int dado){
    fondoMesa(posX,posY);
    bordesMesa(posX,posY);


   ///


    dibujarDados(dado,50,22);




}

void fondoMesa(int posX,int posY){
   rlutil::setColor(rlutil::GREEN);
    for(int x=0;x<80;x++){
        for(int y=0;y<20;y++){
            rlutil::locate(x+posX,y+posY);
            cout<<(char) 219;
        }
    }
}

void bordesMesa(int posX, int posY){
    rlutil::setColor(rlutil::BROWN);

    for(int x=0;x<80;x++){
        rlutil::locate(x+posX,posY);
            cout<<(char) 219;
}
    for(int x=0;x<80;x++){
        rlutil::locate(x+posX,posY+20);
            cout<<(char) 219;
}

    for(int y=0;y<19;y++){
       rlutil::locate(posX-1,y+posY+1);
            cout<<(char) 219;
    }

    for(int y=0; y<19;y++){
    rlutil::locate(posX+80,y+posY+1);
        cout<<(char) 219;

    }

}


