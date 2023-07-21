#include <iostream>
#include "mesaydados.h"
#include "rlutil.h"
#include "estructuras.h"
#include "LogicaDosJugadores.h"
#include "lab.h"

using namespace std;


/// juega hasta que gane alguno si gana el 2 se intercambian nombres

void jugarPorTurnoLab(jugadores vJugadores[2], estatuas& estatuillas)
{

    bool salir = false;

    while(salir != true)
    {


/// tira jugador 1

        system("cls");
        mesa();
        mostrarDatosJugadorUno(vJugadores);
        lanzarUnDadoDiezCarasLab(vJugadores,0);




        /// tiempo intermedio
        Sleep(2000);


        /// tira jugador 2

        system("cls");
        mesa();
        mostrarDatosJugadorDos(vJugadores);

        lanzarUnDadoDiezCarasLab(vJugadores,1);


        Sleep(2000);



        /// si gana el jugador 1
        if(vJugadores[0].dados[0]<vJugadores[1].dados[0])
        {



            borrarCout();
            rlutil::locate(30,25);
            cout<<"Empieza el jugador: "<<vJugadores[0].nombre;
            Sleep(1500);
            salir = true;
            system("cls");
        }


        /// si gana el jugador 2 intercambian nombres
        else if(vJugadores[1].dados[0]<vJugadores[0].dados[0])
        {

            string nAux = vJugadores[0].nombre;

            vJugadores[0].nombre = vJugadores[1].nombre;
            vJugadores[1].nombre = nAux;



             borrarCout();
            rlutil::locate(30,25);
            cout<<"Empieza el jugador: "<<vJugadores[0].nombre;
            Sleep(1500);
            salir = true;
            system("cls");
        }

    }

}










 void lanzarUnDadoDiezCarasLab(jugadores vJugadores[2],int jugadorActual){

    int dadoUno;

 /// pedimos los valores de los dados

     borrarCin();
    borrarCout();
    rlutil::locate(30,25);
    cout<<"Ingrese dado a lanzar";

    rlutil::locate(30,28);
    cin>>dadoUno;



    /// se cargan los vectores de dados manualmente
    vJugadores[jugadorActual].dados[0]=dadoUno;

    dado10Caras(dadoUno);
 }






void lanzarCincoDadosSeisCarasLab(jugadores vJugadores[2],int jugadorActual){

    int dado;

/// pedimos los valores de los dados

    borrarCout();
    borrarCin();
    rlutil::locate(30,25);
    cout<<"Ingrese dados a lanzar";

   for(int i=0;i<5;i++){

    /// por cada vuelta llenamos el vector de dados del jugador actual
    borrarCin();
    rlutil::locate(30,28);
    cin>>dado;
    vJugadores[jugadorActual].dados[i]=dado;

   }

   /// muestra el dibujo de los dados del vector
   cincoDadosSeisCaras(vJugadores,jugadorActual);

}





void lanzarDosDadosDiezCarasLab(jugadores vJugadores[2],int jugadorActual){

     int dado;

     for(int i=0;i<2;i++){

    /// por cada vuelta llenamos el vector de dados del jugador actual
    borrarCin();
    rlutil::locate(30,28);
    cin>>dado;
    vJugadores[jugadorActual].dados[i]=dado;

   }

     /// muestra el dibujo de los dados del vector
   dosDadosDiezCaras(vJugadores,jugadorActual);
}





void lanzarTresDadosDiezCarasLab(jugadores vJugadores[2],int jugadorActual){


    int dado;

     for(int i=0;i<3;i++){

    /// por cada vuelta llenamos el vector de dados del jugador actual
    borrarCin();
    rlutil::locate(30,28);
    cin>>dado;
    vJugadores[jugadorActual].dados[i]=dado;

   }

    /// muestra el dibujo de los dados del vector
    tresDadosDiezCaras(vJugadores,jugadorActual);

}



bool evaluarMaldicionSalamandraLab(jugadores vJugadores[2],int nroJugadorActual)
{


    int nroJugador;


    switch(nroJugadorActual)
    {
    case 0:
        nroJugador = 1;

        break;

    case 1:
        nroJugador = 0;
        break;

    }

    /// evalua si el rival tiene la maldicion
    /// si la tiene el jugador actual lanza 3 dados en vez de 2

    if(vJugadores[nroJugador].vEstatuillasObtenidas[4])
    {

        return true;
    }
    else
    {
        return false;
    }

}















void evaluarSeleccionTresDadosLab(int seleccion,int jugadorActual,jugadores vJugadores[2],estatuas& estatuillas)
{


    /// reconoce al jugador actual y a su rival
    int jugadorRival;

    if(jugadorActual == 0)
    {
    jugadorRival = 1;

    }
    if(jugadorActual == 1)
    {
        jugadorRival = 0;
    }

     /// variables de dados a evaluar

    int dadoUno,dadoDos,dadoTres;

    /// selecciona dado

    borrarCin();
    borrarCout();
    rlutil::locate(30,25);
    cout<<"Ingrese dados a lanzar, del 1 al 10";

   /// el jugador actual lanza dos dados
   lanzarTresDadosDiezCarasLab(vJugadores,jugadorActual);




    /// se cargan las variables con los dados del vector del jugador actual
    dadoUno = vJugadores[jugadorActual].dados[0];
    dadoDos =vJugadores[jugadorActual].dados[1];
    dadoTres = vJugadores[jugadorActual].dados[2];




    /// evalua si se ganó o no la estatuilla, cambia el estado de estatuillas del jugador, y estatuillas globales
    ///  lanza un mensaje si gano o no la estatuilla



    switch(seleccion)
    {

    case 0:

        vJugadores[jugadorActual].intentoCangrejo++;

        if(cangrejo_tres(dadoUno,dadoDos,dadoTres))
        {
            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<" Ganaste la estatuilla: "<< estatuillas.vEstatuillas[seleccion];
            PuntosExpedicion(vJugadores[jugadorActual].PuntosEst , vJugadores[jugadorActual].PuntosEstMas , vJugadores[jugadorRival].PuntosEstMenos , vJugadores[jugadorActual].intentoCangrejo);
            Sleep(1500);

            borrarCout();
            rlutil::locate(30,25);

            cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza Un dado, del 1 al 10 ";
            Sleep(2000);

            borrarCout();
            rlutil::locate(30,25);
            lanzarUnDadoDiezCarasLab(vJugadores,jugadorRival);

            borrarCout();
            vJugadores[jugadorActual].PuntosCangrejo -= vJugadores[jugadorRival].dados[0];
            rlutil::locate(30,25);
            cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0]<< " puntos "<<"al jugador "<<vJugadores[jugadorActual].nombre;

            Sleep(1500);


            break;

        }
        else
        {
            borrarCout();
            rlutil::locate(30,25);
            cout <<"No ganaste la estatuilla";

            break;
        }

    case 1:

        vJugadores[jugadorActual].intentoHormiga++;

        if(hormiga_tres(dadoUno,dadoDos,dadoTres))
        {

            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla: "<< estatuillas.vEstatuillas[seleccion];
            PuntosExpedicion(vJugadores[jugadorActual].PuntosEst , vJugadores[jugadorActual].PuntosEstMas , vJugadores[jugadorRival].PuntosEstMenos , vJugadores[jugadorActual].intentoHormiga);
            Sleep(1500);

             borrarCout();
            rlutil::locate(30,25);

            cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza dos dados, del 1 al 10 ";
            Sleep(2000);

            borrarCout();
            rlutil::locate(30,25);
            lanzarDosDadosDiezCarasLab(vJugadores,jugadorRival);

            borrarCout();
            vJugadores[jugadorActual].PuntosHormiga -= ( vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1]);
            rlutil::locate(30,25);
            cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1] << " puntos "<<"al jugador "<<vJugadores[jugadorActual].nombre;

            Sleep(1500);

            break;

        }
        else
        {
            borrarCout();
            rlutil::locate(30,25);
            cout <<"No ganaste la estatuilla";

            break;
        }


    case 2:

        vJugadores[jugadorActual].intentoMedusa++;

        if(medusa_tres(dadoUno,dadoDos,dadoTres))
        {


            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla: "<< estatuillas.vEstatuillas[seleccion];
            PuntosExpedicion(vJugadores[jugadorActual].PuntosEst , vJugadores[jugadorActual].PuntosEstMas , vJugadores[jugadorRival].PuntosEstMenos , vJugadores[jugadorActual].intentoMedusa);

            Sleep(1000);

            break;

        }
        else
        {
            borrarCout();
            rlutil::locate(30,25);
            cout <<"No ganaste la estatuilla";

            break;
        }



    case 3:
        vJugadores[jugadorActual].intentoAguila++;

        if(aguila_tres(dadoUno,dadoDos,dadoTres))
        {


            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla: "<< estatuillas.vEstatuillas[seleccion];
            PuntosExpedicion(vJugadores[jugadorActual].PuntosEst , vJugadores[jugadorActual].PuntosEstMas , vJugadores[jugadorRival].PuntosEstMenos , vJugadores[jugadorActual].intentoAguila);

            Sleep(1000);

            break;

        }
        else
        {
            borrarCout();
            rlutil::locate(30,25);
            cout <<"No ganaste la estatuilla";

            break;
        }


    }

}














void evaluarSeleccionDosDadosLab(int seleccion,int jugadorActual,jugadores vJugadores[2],estatuas& estatuillas)
{

    /// reconoce al jugador actual y a su rival
    /// se llenan sus respectivos vectores de dados
    int jugadorRival;


    if(jugadorActual == 0)
    {

        jugadorRival = 1;

    }
    if(jugadorActual == 1)
    {

        jugadorRival = 0;

    }



    /// variables de dados a evaluar

    int dadoUno,dadoDos;

    /// selecciona dado

    borrarCin();
    borrarCout();
    rlutil::locate(30,25);
    cout<<"Ingrese dados a lanzar, del 1 al 10 ";

   /// el jugador actual lanza dos dados
   lanzarDosDadosDiezCarasLab(vJugadores,jugadorActual);




    /// se cargan las variables con los dados del vector del jugador actual
    dadoUno = vJugadores[jugadorActual].dados[0];
    dadoDos =vJugadores[jugadorActual].dados[1];







    /// evalua si se ganó o no la estatuilla, cambia el estado de estatuillas del jugador, y estatuillas globales
    ///  lanza un mensaje si gano o no la estatuilla


    switch(seleccion)
    {

    case 0:
        vJugadores[jugadorActual].intentoCangrejo++;

        if(cangrejo(dadoUno,dadoDos))
        {
            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<" Ganaste la estatuilla: "<< estatuillas.vEstatuillas[seleccion];
            PuntosExpedicion(vJugadores[jugadorActual].PuntosEst , vJugadores[jugadorActual].PuntosEstMas , vJugadores[jugadorRival].PuntosEstMenos , vJugadores[jugadorActual].intentoCangrejo);

            Sleep(1500);

            ///


            borrarCout();
            rlutil::locate(30,25);

            cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza Un dado, del 1 al 10";
            Sleep(2000);


            lanzarUnDadoDiezCarasLab(vJugadores,jugadorRival);


            borrarCout();
            vJugadores[jugadorActual].PuntosCangrejo -= vJugadores[jugadorRival].dados[0];
            rlutil::locate(30,25);
            cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0]<< " puntos "<<"al jugador "<<vJugadores[jugadorActual].nombre;

            Sleep(1500);

            break;

        }
        else
        {
            borrarCout();
            rlutil::locate(30,25);
            cout <<"No ganaste la estatuilla";

            break;
        }

    case 1:
        vJugadores[jugadorActual].intentoHormiga++;

        if(hormiga(dadoUno,dadoDos))
        {
            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla: "<< estatuillas.vEstatuillas[seleccion];
            PuntosExpedicion(vJugadores[jugadorActual].PuntosEst , vJugadores[jugadorActual].PuntosEstMas , vJugadores[jugadorRival].PuntosEstMenos , vJugadores[jugadorActual].intentoHormiga);

            Sleep(1500);

             borrarCout();
            rlutil::locate(30,25);

            cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza dos dados, del 1 al 10";
            Sleep(2000);


            lanzarDosDadosDiezCarasLab(vJugadores,jugadorRival);

            borrarCout();
            vJugadores[jugadorActual].PuntosHormiga -= ( vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1]);
            rlutil::locate(30,25);
            cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1] << " puntos "<<"al jugador "<<vJugadores[jugadorActual].nombre;

            Sleep(1500);



            break;

        }
        else
        {
            borrarCout();
            rlutil::locate(30,25);
            cout <<"No ganaste la estatuilla";

            break;
        }




    case 2:
        vJugadores[jugadorActual].intentoMedusa++;

        if(medusa(dadoUno,dadoDos))
        {


            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla: "<< estatuillas.vEstatuillas[seleccion];
            PuntosExpedicion(vJugadores[jugadorActual].PuntosEst , vJugadores[jugadorActual].PuntosEstMas , vJugadores[jugadorRival].PuntosEstMenos , vJugadores[jugadorActual].intentoMedusa);

            Sleep(1000);

            break;

        }
        else
        {
            borrarCout();
            rlutil::locate(30,25);
            cout <<"No ganaste la estatuilla";

            break;
        }



    case 3:
        vJugadores[jugadorActual].intentoAguila++;

        if(aguila(dadoUno,dadoDos))
        {


            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla: "<< estatuillas.vEstatuillas[seleccion];
            PuntosExpedicion(vJugadores[jugadorActual].PuntosEst , vJugadores[jugadorActual].PuntosEstMas , vJugadores[jugadorRival].PuntosEstMenos , vJugadores[jugadorActual].intentoAguila);

            Sleep(1000);

            break;

        }
        else
        {
            borrarCout();
            rlutil::locate(30,25);
            cout <<"No ganaste la estatuilla";

            break;
        }

    case 4:
        vJugadores[jugadorActual].intentoSalamandra++;

        if(salamandra(dadoUno,dadoDos))
        {


            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla: "<< estatuillas.vEstatuillas[seleccion];
            PuntosExpedicion(vJugadores[jugadorActual].PuntosEst , vJugadores[jugadorActual].PuntosEstMas , vJugadores[jugadorRival].PuntosEstMenos , vJugadores[jugadorActual].intentoSalamandra);

            Sleep(1000);

            break;

        }
        else
        {
            borrarCout();
            rlutil::locate(30,25);
            cout <<"No ganaste la estatuilla";

            break;
        }

    }

}
