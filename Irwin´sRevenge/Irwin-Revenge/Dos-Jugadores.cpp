#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "mesa.h"


#include "mesaydados.h"


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





/// pasar a otro cpp
void jugarPorTurno(jugadores vjugadores[]);





/// a otro cpp
void dibujarEstatuilla(estatuas);



/// a otro cpp
void pedirDatos(jugadores []);




int terminarExpedicion(estatuas);












void LAB1 ();








void dosJugadores()
{

    bool fin = false;

    /// variables de struct

    jugadores vJugadores[2];
    estatuas estatuillas;



    /// pide los nombres de los 2 jugadores
    rlutil::cls();

    pedirDatos(vJugadores);

    rlutil::cls();




    /// si es LAB1 , va a la funcion predestinada
    if(vJugadores[0].nombre == "LAB1")
    {

        rlutil::cls();
        LAB1();
    }

    else
    {
        do
        {


            int dado1 = 1+ (rand()%10);
            int dado2 = 1+ (rand()%10);




            jugarPorTurno(vJugadores);








            /// turno en fase de expedicion


            while(terminarExpedicion(estatuillas) != 5)
            {

                Sleep(2000);

                ///  dibuja las estatuillas disponibles
                dibujarEstatuilla(estatuillas);





                /// cambio de turnos

                if(vJugadores[0].turnoPrimero)
                {



                    mesa(30,5);


                    rlutil::anykey();
                    dosDadosSeisCaras(30,5,dado1);
                    datosEnJuego(vJugadores);













                    vJugadores[0].turnoPrimero = false;
                    vJugadores[1].turnoPrimero = true;



                }
                else
                {

                    mesa(30,5);


                    rlutil::anykey();
                    dosDadosSeisCaras(30,5,dado2);
                    datosEnJuego(vJugadores);











                    vJugadores[1].turnoPrimero = false;
                    vJugadores[0].turnoPrimero = true;



                }






            }






            /*



                    vJugadores[0].turnoPrimero = false;

                    vJugadores[0].vEstatuillasObtenidas[0]= cangrejo(dadoUno,dadoDos);

                    if(vJugadores[0].vEstatuillasObtenidas[0])
                    {

                        estatuillas.vEstatuillasDisponibles[0]=0;

                    }




            */







        }
        while(fin != true);

    }

}



///--------------------- Funcion 2 jugadores SI LAB1 ----------------------------------




/// pasar a otro cpp

int terminarExpedicion(estatuas estatuillas)
{

    int cont = 0;


    for(int i=0; i<5; i++)
    {


        if(!estatuillas.vEstatuillasDisponibles[i])

            cont++;
    }

    if(cont == 5)
    {

        return cont;

    }

    return 0;


}






















/// pasar a otro cpp

void jugarPorTurno(jugadores vJugadores[])
{




    int t=1;


      system("cls");

    while(t != 0)
    {

        srand(time(0));


        int dado1 = 1+ (rand()%10);
        int dado2 = 1+ (rand()%10);






        /// turno jugador 1

        vJugadores[1].turnoPrimero = false;
        vJugadores[0].turnoPrimero = true;



        datosEnJuego(vJugadores);
        mesa(30,5);


        rlutil::anykey();
        dado10Caras(30,5,dado1);

        system("cls");



        Sleep(1000);











        /// turno jugador 2

        vJugadores[0].turnoPrimero = false;
        vJugadores[1].turnoPrimero = true;

        datosEnJuego(vJugadores);
        mesa(30,5);


        rlutil::anykey();
        dado10Caras(30,5,dado2);









        Sleep(1000);

         system("cls");




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
                dado1 = 1+ (rand()%10);
                dado2 = 1+ (rand()%10);
                rlutil::cls();

            }
            else
            {
                vJugadores[0].turnoPrimero = false;
                vJugadores[1].turnoPrimero = true;


                t = 0;



            }
        }
    }


}

























int cangrejo(int d1, int d2)
{
    int v1=d1%2, v2=d2%2;
    if((v1==0 && v2!=0) || (v1!=0 && v2==0))
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
    else if(vJugadores[1].turnoPrimero)
    {

        rlutil::locate(3,3);
        cout<<"JUGADOR : " <<vJugadores[1].nombre;

        rlutil::locate(20,3);
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



