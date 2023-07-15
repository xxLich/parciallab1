#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"

using namespace std;




void dibujarCuadrado(int posX,int posY){
    rlutil::setColor(rlutil::BLACK);
    for(int x=0;x<7;x++){
        for(int y=0;y<3;y++){
            rlutil::locate(x+posX,y+posY);
            cout<<(char)219<<endl;
        }
    }
}



void dibujarDados(int numero,int posX,int posY){
        dibujarCuadrado(posX,posY);
        dibujarPuntos(numero,posX,posY);
}




void dibujarPuntos(int numero,int posX,int posY){

    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

    switch(numero){
case 1:
    rlutil::locate(posX+3,posY+1);
    cout<<(char)254;



    break;
case 2:
    rlutil::locate(posX+1,posY);
    cout<<(char) 254;
    rlutil::locate(posX+5,posY+2);
    cout<<(char) 223;
break;



case 3:
///arriba
rlutil::locate(posX+1,posY);
    cout<<(char) 254;
///medio
 rlutil::locate(posX+3,posY+1);
    cout<<(char)254;
///bajo
    rlutil::locate(posX+5,posY+2);
    cout<<(char) 223;
break;



case 4:


///arriba
rlutil::locate(posX+1,posY);
    cout<<(char) 254;

 rlutil::locate(posX+1,posY+2);
    cout<<(char)223;
///bajo
    rlutil::locate(posX+5,posY+2);
    cout<<(char) 223;

rlutil::locate(posX+5,posY);
    cout<<(char) 254;

break;


case 5:

///arriba
rlutil::locate(posX+1,posY);
    cout<<(char) 254;

 rlutil::locate(posX+1,posY+2);
    cout<<(char)223;

///medio
     rlutil::locate(posX+3,posY+1);
    cout<<(char)254;
///bajo
    rlutil::locate(posX+5,posY+2);
    cout<<(char) 223;

rlutil::locate(posX+5,posY);
    cout<<(char) 254;

break;

case 6:
///arriba
rlutil::locate(posX+1,posY);
    cout<<(char) 254;

 rlutil::locate(posX+1,posY+2);
    cout<<(char)223;
///medio
     rlutil::locate(posX+3,posY);
    cout<<(char)254;

///bajo
    rlutil::locate(posX+5,posY+2);
    cout<<(char) 223;

rlutil::locate(posX+5,posY);
    cout<<(char) 254;
///medio
     rlutil::locate(posX+3,posY+2);
    cout<<(char)223;


break;


case 7:
///arriba
rlutil::locate(posX+1,posY);
    cout<<(char) 254;

 rlutil::locate(posX+1,posY+2);
    cout<<(char)223;
///medio
     rlutil::locate(posX+3,posY);
    cout<<(char)254;
///medio
     rlutil::locate(posX+3,posY+1);
    cout<<(char)254;
///bajo
    rlutil::locate(posX+5,posY+2);
    cout<<(char) 223;

rlutil::locate(posX+5,posY);
    cout<<(char) 254;
///medio
     rlutil::locate(posX+3,posY+2);
    cout<<(char)223;


break;

case 8:
///arriba
rlutil::locate(posX+1,posY);
    cout<<(char) 254;

 rlutil::locate(posX+1,posY+2);
    cout<<(char)223;
///medio
     rlutil::locate(posX+3,posY);
    cout<<(char)254;
///medio
     rlutil::locate(posX+1,posY+1);
    cout<<(char)254;
     rlutil::locate(posX+5,posY+1);
    cout<<(char)254;
///bajo
    rlutil::locate(posX+5,posY+2);
    cout<<(char) 223;

rlutil::locate(posX+5,posY);
    cout<<(char) 254;
///medio
     rlutil::locate(posX+3,posY+2);
    cout<<(char)223;


break;


case 9:
///arriba
rlutil::locate(posX+1,posY);
    cout<<(char) 254;

 rlutil::locate(posX+1,posY+2);
    cout<<(char)223;


///medio
     rlutil::locate(posX+3,posY+1);
    cout<<(char)254;

///medio
     rlutil::locate(posX+3,posY);
    cout<<(char)254;
///medio
     rlutil::locate(posX+1,posY+1);
    cout<<(char)254;
     rlutil::locate(posX+5,posY+1);
    cout<<(char)254;
///bajo
    rlutil::locate(posX+5,posY+2);
    cout<<(char) 223;

rlutil::locate(posX+5,posY);
    cout<<(char) 254;
///medio
     rlutil::locate(posX+3,posY+2);
    cout<<(char)223;


break;
case 10:

   rlutil::locate(posX+2,posY+1);
    cout<<(char)49;
      rlutil::locate(posX+4,posY+1);
    cout<<(char)48;

    break;



    }




}
















































