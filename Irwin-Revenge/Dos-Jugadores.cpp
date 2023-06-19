#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"
#include <string>
#include <cstdlib>
#include "mesa.h"



using namespace std;







struct estatuas {

    string estatuillas[5] = {"cangrejo","hormiga","medusa","aguila","salamandra"};
    bool estadoEstatuilla[5] = {1,1,1,1,1};


};

struct jugadores {

    string nombre;
    string estatuillas[5] = {"cangrejo","hormiga","medusa","aguila","salamandra"};
    bool estadoEstatuilla[5] = {};
    int puntos = 0;


};




void dibujarEstatuilla(estatuas);


void pedirDatos(jugadores []);

void LAB1 ();






estatuas estatuillas;





void dosJugadores()
{

    int puntos = 0;

    int vectDados[10];

    bool fin = false;

    jugadores players[2];



     rlutil::cls();
    pedirDatos(players);

    rlutil::cls();







    if(players[0].nombre == "LAB1")
    {

        rlutil::cls();

        LAB1();

    }

    else

    {

        int dado =0;


        do
        {

        dado++;
        if(dado == 10){

            dado = 1;

        }




            rlutil::locate(1,33);

            rlutil::anykey(" Presione un boton para lanzar ");



            /// almacena los 10 dados por cada vuelta

            llenarVector(vectDados,10);





            int xmesa = 30, ymesa = 10;
            dibujarMesa(xmesa,ymesa);


            dibujarEstatuilla(estatuillas);




        }
        while(fin != true);

    }

}



///--------------------- Funcion 2 jugadores SI LAB1 ----------------------------------



void LAB1 ()
{




     int vectDados[6];
    int salir = 1;
    string jugadores[2];





    do
    {





        for(int i=0;i<6;i++){

        cout<<"Ingre su seleccion de dado"<<endl;
        cin>>vectDados[i];

        }




    }
    while(salir != 0);



}





void dibujarEstatuilla(estatuas est){


 int posx = 1 , posy = 10;



    for(int i=0;i<5;i++){

    posy+=2;



    if(est.estadoEstatuilla[i]){

        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(posx,posy);
        cout<<est.estatuillas[i];


    }

    }

}













/// pasar a otro cpp

void pedirDatos(jugadores player[])
{

    for(int x=0; x<2; x++)
    {
        cout << "Nombre del jugador "<<x+1<<endl;
        cin >> player[x].nombre;

    }

}



