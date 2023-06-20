#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"

using namespace std;



/// llena un vector de 6 con numeros aleatorios

void llenarVector(int vectDados[], int tam)
{

    int dado;
    int vueltas = 0;

    while(vueltas <10)
    {

        dado = 1 + rand() % 10 -1;

        if(dado > 0 && dado <=10 )
        {

            vectDados[vueltas] = dado;

            vueltas++;
        }

    }

}


/// dibuja 6 dados con los elementos del vector

/*void drawSixDados(int vectDados[])
{

    for(int i=0; i<6; i++)
    {

        drawDado(vectDados[i]);

    }




}
*/

void dibujarCuadrado(int posX,int posY){
    rlutil::setColor(rlutil::WHITE);
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

    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);

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









































void drawDado(int n)
{



    switch (n)
    {

   case 1:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< "       " << char(186)<<endl;
            cout << char(186)<< "   " << char(254) << "   " << char(186)<<endl;
            cout << char(186)<< "       " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;


        case 2:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< "     " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< "       " << char(186)<<endl;
            cout << char(186)<< "     " << char(254) << " " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;



        case 3:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< "     " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< "   " << char(254) << "   " << char(186)<<endl;
            cout << char(186)<< "     " << char(254) << " " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;


        case 4:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< "       " << char(186)<<endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;
        case 5:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< "   " << char(254) << "   "<< char(186)<<endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;


        case 6:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;


    }
}





