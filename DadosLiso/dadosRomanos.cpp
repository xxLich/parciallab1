#include <iostream>
#include "rlutil.h"
#include "dados.h"
#include <cstdlib> ///Libreria para cambiar el color de fondo

using namespace std;


void cuadradoRomano(int posX, int posY){
        rlutil::setColor(rlutil::WHITE);
        ///ancho /2
        for(int x=0; x<20;x++){
        for (int y=0; y<10;y++){
            rlutil::locate(x+posX, y+posY);
            cout<<(char)219<<endl;
        }
    }


}

void dibujarRomano(int numero, int posX, int posY){

    cuadradoRomano(posX,posY);
    dibujarPuntosRomano(numero,posX,posY);
  //  dibujarBordes(posX,posY);


}
void dibujarPuntosRomano(int numero,int posX,int posY){

                rlutil::setColor(rlutil::BLACK);
                rlutil::setBackgroundColor(rlutil::WHITE);


    switch(numero){

case 1:

        rlutil::setColor(rlutil::RED);
        rlutil::locate(posX+7,posY+2);
        for(int x=0;x<6;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+7,posY+7);
         for(int x=0;x<6;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+9,posY+3);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
           rlutil::locate(posX+9,posY+4);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+9,posY+5);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+9,posY+6);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }


    break;

case 2:
        ///linea arriba
    rlutil::setColor(rlutil::BLACK);
        rlutil::locate(posX+2,posY+2);
        for(int x=0;x<6;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        ///linea abajo
        rlutil::locate(posX+2,posY+7);
         for(int x=0;x<6;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        ///medio
        rlutil::locate(posX+4,posY+3);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
           rlutil::locate(posX+4,posY+4);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+4,posY+5);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+4,posY+6);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }

        ///linea arriba
    rlutil::setColor(rlutil::BLACK);
        rlutil::locate(posX+9,posY+2);
        for(int x=0;x<6;x++){
            for(int y=0;y<1;y++){
                cout<<(char)219;
            }


        }
        ///linea abajo
        rlutil::locate(posX+9,posY+7);
         for(int x=0;x<6;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        ///medio
        rlutil::locate(posX+11,posY+3);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
           rlutil::locate(posX+11,posY+4);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+11,posY+5);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+11,posY+6);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }


    break;



case 3:
        ///1
    ///linea arriba
    rlutil::setColor(rlutil::BLACK);
        rlutil::locate(posX+2,posY+2);
        for(int x=0;x<4;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        ///linea abajo
        rlutil::locate(posX+2,posY+7);
         for(int x=0;x<4;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        ///medio
        rlutil::locate(posX+3,posY+3);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
           rlutil::locate(posX+3,posY+4);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+3,posY+5);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+3,posY+6);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        ///2
        ///linea arriba
    rlutil::setColor(rlutil::BLACK);
        rlutil::locate(posX+7,posY+2);
        for(int x=0;x<4;x++){
            for(int y=0;y<1;y++){
                cout<<(char)219;
            }


        }
        ///linea abajo
        rlutil::locate(posX+7,posY+7);
         for(int x=0;x<4;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        ///medio
        rlutil::locate(posX+8,posY+3);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
           rlutil::locate(posX+8,posY+4);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+8,posY+5);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+8,posY+6);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
///3
        ///linea arriba
    rlutil::setColor(rlutil::BLACK);
        rlutil::locate(posX+12,posY+2);
        for(int x=0;x<4;x++){
            for(int y=0;y<1;y++){
                cout<<(char)219;
            }


        }
        ///linea abajo
        rlutil::locate(posX+12,posY+7);
         for(int x=0;x<4;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        ///medio
        rlutil::locate(posX+13,posY+3);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
           rlutil::locate(posX+13,posY+4);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+13,posY+5);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }
        rlutil::locate(posX+13,posY+6);
         for(int x=0;x<2;x++){
            for(int y=0;y<1;y++){

                cout<<(char)219;
            }


        }


break;


case 4:







    break;


}}
