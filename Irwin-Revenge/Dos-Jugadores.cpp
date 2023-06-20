#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"
#include <string>
#include <cstdlib>
#include "mesa.h"


using namespace std;





struct estatuas
{

    string vEstatuillas[5] = {"1.cangrejo","2.hormiga","3.medusa","4.aguila","5.salamandra"};
    bool vEstatuillasDisponibles[5] = {1,1,1,1,1};


};

struct jugadores
{

    string nombre;
    string vEstatuillas[5] = {"|cangrejo|","|hormiga|","|medusa|","|aguila|","|salamandra|"};
    bool vEstatuillasObtenidas[5] = {};
    int puntos = 0;
    bool turnoPrimero = 0;


};



///

int cangrejo(int, int);













/// a otro cpp

void datosEnJuego(jugadores[]);


/// a otro cpp
/// devuelve el indice del jugador que empieza primero

/*
int primeroEnLanzar(){

        srand(time(nullptr));

        int dado = rand()%10+1;







      int xmesa = 30, ymesa = 10;
           dibujarMesa(xmesa,ymesa,dado);


}

*/


/// a otro cpp
void dibujarEstatuilla(estatuas);


void pedirDatos(jugadores []);

void LAB1 ();








void dosJugadores()
{

    bool fin = false;

    /// variables de struct

    jugadores vJugadores[2];
    estatuas estatuillas;




    rlutil::cls();

    pedirDatos(vJugadores);

    rlutil::cls();



    if(vJugadores[0].nombre == "LAB1")
    {

        rlutil::cls();
        LAB1();
    }

    else
    {
        do
        {

            int dado1 = 2;
            int dado2 = 2;


            int t=1;

            while(t != 0)
            {


                vJugadores[1].turnoPrimero = false;
                vJugadores[0].turnoPrimero = true;




                cout<<dado1<<endl;


                    rlutil::anykey();




                 vJugadores[0].turnoPrimero = false;
                vJugadores[1].turnoPrimero = true;





                cout<<dado2<<endl;
                Sleep(2000);















                if(dado1<dado2)
                {

                    vJugadores[1].turnoPrimero = false;
                    vJugadores[0].turnoPrimero = true;
                    t = 0;

                }
                else
                {
                    if(dado1==dado2)
                    {
                        dado1 = rand()%10+1;
                        dado2 = rand()%10+1;

                    }
                    else
                    {
                        vJugadores[0].turnoPrimero = false;
                        vJugadores[1].turnoPrimero = true;
                        t = 0;
                    }
                }
            }




                datosEnJuego(vJugadores);















            /*


                    datosEnJuego(vJugadores);

                    vJugadores[0].turnoPrimero = false;

                    vJugadores[0].vEstatuillasObtenidas[0]= cangrejo(dadoUno,dadoDos);

                    if(vJugadores[0].vEstatuillasObtenidas[0])
                    {

                        estatuillas.vEstatuillasDisponibles[0]=0;

                    }
                    else
                    {



                    }



            */










            rlutil::locate(1,32);

            rlutil::anykey(" Presione un boton para lanzar ");



            int xmesa = 30, ymesa = 10;
            dibujarMesa(xmesa,ymesa,dado1);



            ///    dibujarEstatuilla(estatuillas);
            dibujarEstatuilla(estatuillas);




        }
        while(fin != true);

    }

}



///--------------------- Funcion 2 jugadores SI LAB1 ----------------------------------




int cangrejo(int d1, int d2)
{
    int v1=d1%2, v2=d2%2;
    if(v1==0 && v2!=0 || v1!=0 && v2==0)
    {
        return 1;
    }
    return 0;
}



















void LAB1 ()
{




    int vectDados[6];
    int salir = 1;
    string jugadores[2];





    do
    {





        for(int i=0; i<6; i++)
        {

            cout<<"Ingre su seleccion de dado"<<endl;
            cin>>vectDados[i];

        }




    }
    while(salir != 0);



}



void datosEnJuego(jugadores vJugadores[])
{

    int datoEstatuillaX = 35;


    if(vJugadores[0].turnoPrimero)
    {

        rlutil::locate(3,3);
        cout<<"JUGADOR : " <<vJugadores[0].nombre;

        rlutil::locate(20,3);
        cout<<"ESTATUILLAS OBTENIDAS : ";

        for(int i=0; i<5; i++)
        {

            if(vJugadores[0].vEstatuillasObtenidas[i])
            {


                rlutil::locate(datoEstatuillaX += 10,3);
                cout<<vJugadores[0].vEstatuillas[i];

            }

        }

    }


    if(vJugadores[1].turnoPrimero)
    {

        rlutil::locate(3,3);
        cout<<"JUGADOR : " <<vJugadores[1].nombre;

        rlutil::locate(8,3);
        cout<<"ESTATUILLAS OBTENIDAS : ";


        for(int i=0; i<5; i++)
        {

            if(vJugadores[1].vEstatuillasObtenidas[i])
            {


                rlutil::locate(datoEstatuillaX += 10,3);
                cout<<vJugadores[1].vEstatuillas[i];

            }

        }



    }



}


























void dibujarEstatuilla(estatuas est)
{


    int posx = 1, posy = 10;



    for(int i=0; i<5; i++)
    {

        posy+=2;



        if(est.vEstatuillasDisponibles[i])
        {

            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(posx,posy);
            cout<<est.vEstatuillas[i];


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



