#include <iostream>
#include "dado.h"
#include "mesaydados.h"
#include "estructuras.h"
#include "rlutil.h"
#include <ctime>
#include <cstdlib>
#include "LogicaDosJugadores.h"

using namespace std;

void seleccionarEstatuilla(int , jugadores[], estatuas);

void datosEnJuego(jugadores[]);

void jugarPorTurno(jugadores vjugadores[]);

void dibujarEstatuilla(estatuas);

void pedirDatos(jugadores []);

int terminarExpedicion(estatuas);

void cambiarTurnos(jugadores []);

void LAB1 ();

void mostrarDatosJugadorUno(jugadores []);

void mostrarDatosJugadorDos(jugadores []);






/// Pide nombre a cada jugador y lo almacena

void pedirDatos(jugadores vjugadores[2])
{

    for(int x=0; x<2; x++)
    {
        cout << "Nombre del jugador "<<x+1<<endl;
        cin >> vjugadores[x].nombre;

    }

}


/// muestra estatuillas disponibles para todos

void dibujarEstatuilla(estatuas est)
{

    int posx = 1, posy = 10;

    for(int i=0; i<5; i++)
    {

        posy+=2;

        if(est.vEstatuillasDisponibles[i])
        {



            rlutil::locate(posx,posy);
            cout<<est.vEstatuillas[i];
        }



    }

}


void mostrarDatosJugadorDos(jugadores vJugadores[2])
{


    int datoEstatuillaX = 35;

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


void mostrarDatosJugadorUno(jugadores vJugadores[2])
{



    int datoEstatuillaX = 35;


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





///CARGA VECTORES DE LOS DADOS
void llenarVectorDados(jugadores vJugadores[2])
{


    srand(time(0));

    for(int i=0; i<5; i++)
    {

        vJugadores[0].dados[i]= 1+ (rand()%10);
        vJugadores[1].dados[i]= 1+ (rand()%10);
    }

}






/// Muestra los datos del jugador con turnoActual en true
/// nombre , estatuillas obtenidas
void datosEnJuego(jugadores vJugadores[])
{

    int datoEstatuillaX = 30;


    if(vJugadores[0].turnoPrimero)
    {

        rlutil::locate(3,3);
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
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
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
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


/// devuelve int 5 si ya no hay estatuillas disponibles

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


/// cambia los estados de turnoPrimero

void cambiarTurnos(jugadores vJugadores[2])
{

    if(vJugadores[0].turnoPrimero)
    {


        vJugadores[0].turnoPrimero = false;
        vJugadores[1].turnoPrimero = true;

    }
    else
    {

        vJugadores[1].turnoPrimero = false;
        vJugadores[0].turnoPrimero = true;

    }


}
///Lan dados


void lanzarUnDadoDiezCaras(jugadores vJugadores[2],int nroJugador){

        rlutil::locate(30, 25);
    rlutil::anykey("Pulse una tecla para lanzar");
    dado10Caras(vJugadores[nroJugador].dados[0]);



}



void lanzarDosDadosDiezCaras(jugadores vJugadores[2],int nroJugador)
{

     rlutil::locate(30, 25);
    rlutil::anykey("Pulse una tecla para lanzar");
    dosDadosDiezCaras(vJugadores,nroJugador);

}


void lanzarTresDadosDiezCaras(jugadores vJugadores[2], int nroJugador)
{

     rlutil::locate(30, 25);
    rlutil::anykey("Pulse una tecla para lanzar");
    tresDadosDiezCaras(vJugadores,nroJugador);

}


void lanzarCincoDadosSeisCaras(jugadores vJugadores[2],int nroJugador)
{
     rlutil::locate(30, 25);
    rlutil::anykey("Pulse una tecla para lanzar");
    cincoDadosSeisCaras(vJugadores,nroJugador);

}


/// juega hasta que gane alguno y sale con tu estado en true

void jugarPorTurno(jugadores vJugadores[2])
{
    string nAux;

    int t=1;

    while(t != 0)
    {

        srand(time(0));


        int dado1 = 1+ (rand()%10);
        int dado2 = 1+ (rand()%10);

        /// turno jugador 1

        vJugadores[1].turnoPrimero = false;
        vJugadores[0].turnoPrimero = true;



        datosEnJuego(vJugadores);
        mesa();

        rlutil::locate(30, 25);
    cout << "                                                       ";
        rlutil::locate(30, 25);
        rlutil::anykey("Presiona una tecla para lanzar");
        dado10Caras(dado1);


        Sleep(1000);


        /// turno jugador 2

        vJugadores[0].turnoPrimero = false;
        vJugadores[1].turnoPrimero = true;

        datosEnJuego(vJugadores);
        mesa();


    rlutil::locate(30, 25);
        cout << "                                                       ";
        rlutil::locate(30, 25);
        rlutil::anykey("Presiona una tecla para lanzar");
        dado10Caras(dado2);

        Sleep(1000);



        if(dado1<dado2)
        {

            vJugadores[1].turnoPrimero = false;
            vJugadores[0].turnoPrimero = true;

            rlutil::cls();



            t = 0;

        }
        else
        {
            if(dado1==dado2)
            {
                dado1 = 1+ (rand()%10);
                dado2 = 1+ (rand()%10);
                system("cls");

            }
            else
            {
                vJugadores[0].turnoPrimero = false;
                vJugadores[1].turnoPrimero = true;

                /// si gana el segundo , se cambia el nombre del jugador 1 al nombre del jugador 2

                nAux = vJugadores[0].nombre;
                vJugadores[0].nombre = vJugadores[1].nombre;
                vJugadores[1].nombre = nAux;

                rlutil::cls();

                t = 0;

            }
        }
    }


}





/// OBTENCIONES DE ESTATUILLAS  ******************************************


bool cangrejo(int d1, int d2)
{
    int v1=d1%2, v2=d2%2;
    if((v1==0 && v2!=0) || (v1!=0 && v2==0))
    {
        return true;
    }
    return false;
}


bool hormiga(int d1, int d2)
{
    if(d1<5 && d2<5)
    {
        return true;
    }
    return false;
}



bool medusa(int d1, int d2)
{
    int r=d1+d2;
    if(r==7)
    {
        return true;
    }
    return false;
}


bool aguila(int d1, int d2)
{
    if((d1==1 && d2==10) || (d1==10 && d2==1))
    {
        return true;
    }
    return false;
}


bool salamandra(int d1, int d2)
{
    int r =d2-d1;

    if(r==1)
    {
        return true;
    }
    return false;
}



/// OBTENCION DE ESTATUILLAS 3 DADOS **********************************


bool cangrejo_tres(int d1, int d2, int d3)
{
    int v1=d1%2, v2=d2%2, v3=d3%2;
    if((v1==0 && v2==0 && v3==0) || (v1!=0 && v2!=0 && v3!=0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


bool hormiga_tres(int d1, int d2, int d3)
{
    if((d1<5 && d2<5) || (d1<5 && d3<5) || (d2<5 && d3<5))
    {
        return 1;
    }
    return 0;
}


bool medusa_tres(int d1, int d2, int d3)
{
    int r=d1+d2, r1=d1+d3, r2=d2+d3;
    if(r==7 || r1==7 || r2==7)
    {
        return 1;
    }
    return 0;
}


bool aguila_tres(int d1, int d2, int d3)
{
    if((d1==1 && d2==10) || (d1==10 && d2==1) || (d1==1 && d3==10) || (d1==10 && d3==1) || (d2==1 && d3==10) || (d2==10 && d3==1))
    {
        return 1;
    }
    return 0;
}


