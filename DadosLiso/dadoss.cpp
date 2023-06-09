#include <iostream>
#include "rlutil.h"
#include "dados.h"
using namespace std;

///ROMANOS


///DADOS NORMALES
/*
void dibujarCuadrado(int posX, int posY){
        rlutil::setColor(rlutil::WHITE);
        ///ancho /2
        for(int x=0; x<20;x++){
        for (int y=0; y<10;y++){
            rlutil::locate(x+posX, y+posY);
            cout<<(char)219<<endl;
        }
    }


}

void dibujarDado(int numero, int posX, int posY){

    dibujarCuadrado(posX,posY);
    dibujarPuntos(numero,posX,posY);
  //  dibujarBordes(posX,posY);


}

void dibujarPuntos(int numero,int posX,int posY){
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
}



  /*  switch(numero){





*




case 1:

    ///MEDIO, MODIFICAR
        rlutil::setColor(rlutil::RED);
        rlutil::locate(posX+6,posY+3);
        for(int x=1; x<9;x++){
                cout<<(char)219;
        }
        rlutil::locate(posX+6,posY+4);
          for(int j=0;j<8;j++){
                 cout<<(char)219;
                }
                rlutil::locate(posX+6,posY+5);
          for(int j=0;j<8;j++){
                 cout<<(char)219;
                }
         rlutil::locate(posX+6,posY+6);
          for(int j=0;j<8;j++){
                 cout<<(char)219;
                }

            break;

case 2:


     ///ALTO
    rlutil::locate(posX+2,posY+1);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+2,posY+2);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }

    ///BAJO
    rlutil::locate(posX+15,posY+7);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+15,posY+8);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }



    break;




case 3:

     ///ALTO
    rlutil::locate(posX+2,posY+1);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+2,posY+2);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
    ///MEDIO

    rlutil::locate(posX+8,posY+4);
    for(int i=0;i<4;i++){
        cout<<(char)219;
    }

     rlutil::locate(posX+8,posY+5);
    for(int i=0;i<4;i++){
        cout<<(char)219;
    }


    ///BAJO
    rlutil::locate(posX+15,posY+7);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+15,posY+8);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }

    break;

case 4:


     ///ALTO
    rlutil::locate(posX+2,posY+1);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+2,posY+2);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }


     rlutil::locate(posX+14,posY+1);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+14,posY+2);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }

    ///BAJO

       rlutil::locate(posX+2,posY+7);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+2,posY+8);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }


     rlutil::locate(posX+14,posY+8);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+14,posY+7);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }

    break;
case 5:
     ///ALTO
    rlutil::locate(posX+2,posY+1);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+2,posY+2);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }


     rlutil::locate(posX+14,posY+1);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+14,posY+2);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
    ///MEDIO
      rlutil::locate(posX+8,posY+4);
    for(int i=0;i<4;i++){
        cout<<(char)219;
    }

     rlutil::locate(posX+8,posY+5);
    for(int i=0;i<4;i++){
        cout<<(char)219;
    }
    ///BAJO

       rlutil::locate(posX+2,posY+7);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+2,posY+8);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }


     rlutil::locate(posX+14,posY+8);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+14,posY+7);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }

    break;


case 6:

    ///ALTO
    rlutil::locate(posX+2,posY+1);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+2,posY+2);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }


     rlutil::locate(posX+14,posY+1);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+14,posY+2);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
    ///MEDIO
      rlutil::locate(posX+8,posY+1);
    for(int i=0;i<4;i++){
        cout<<(char)219;
    }

     rlutil::locate(posX+8,posY+2);
    for(int i=0;i<4;i++){
        cout<<(char)219;
    }

          rlutil::locate(posX+8,posY+8);
    for(int i=0;i<4;i++){
        cout<<(char)219;
    }

     rlutil::locate(posX+8,posY+7);
    for(int i=0;i<4;i++){
        cout<<(char)219;
    }
    ///BAJO

       rlutil::locate(posX+2,posY+7);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+2,posY+8);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }


     rlutil::locate(posX+14,posY+8);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }
     rlutil::locate(posX+14,posY+7);
    for(int i=0;i<4;i++){
        cout<<(char)219;

    }

    break;

    }
}

*/


