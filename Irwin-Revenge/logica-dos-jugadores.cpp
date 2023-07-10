#include <iostream>
#include "dado.h"
#include "mesaydados.h"
#include "estructuras.h"
#include "rlutil.h"
#include <ctime>
#include <cstdlib>
#include "LogicaDosJugadores.h"
#include <string>
#include <windows.h>

using namespace std;







/*

/// Estadisticas


void estadisticas(int posX,int posY,jugadores[]);
void nombreJuego(int,int);
void Jugadores(int,int,jugadores[]);




void estadisticas(int posX,int posY,jugadores vJugadores[2]){
nombreJuego(1,1);
Jugadores(1,1,vJugadores);


}

void nombreJuego(int posX,int posY){

cout<<"                      Irwin Revenge - Estadistica del juego - FASE FINAL"                      <<endl;
cout<<"----------------------------------------------------------------------------------------------"<<endl;

}
void Jugadores(int posX,int posY,jugadores vJugadores[2]){

cout<<"HITO";

cout<<"----------------------------------------------------------------------------------------------"<<endl;

cout<<"Estatuilla                     "<<vJugadores[0].PuntosEst<<"                "<<vJugadores[1].PuntosEst<<endl;

cout<<"Estatuilla++                   "<<vJugadores[0].PuntosEstMas<<"                "<<vJugadores[1].PuntosEstMas<<endl;

cout<<"Ganador                        "<<vJugadores[0].PuntosGan<<"                "<<vJugadores[1].PuntosGan<<endl;

cout<<"Ganador++                      "<<vJugadores[0].PuntosGanMas<<"                "<<vJugadores[1].PuntosGanMas<<endl;

cout<<"Est --                         "<<vJugadores[0].PuntosEstMenos<<"                "<<vJugadores[1].PuntosEstMenos<<endl;

cout<<"Lanzamiento                    "<<vJugadores[0].PuntosEst<<"                "<<vJugadores[1].PuntosEst<<endl;
cout<<"----------------------------------------------------------------------------------------------"<<endl;

cout<<"TOTAL                          "<<vJugadores[0].PuntosTotal<<"              "<<vJugadores[1].PuntosTotal <<endl;

cout<<"----------------------------------------------------------------------------------------------"<<endl;

string ganador;
if(vJugadores[0].PuntosTotal>vJugadores[1].PuntosTotal){
    ganador=vJugadores[0].nombre;
}else{

    ganador = vJugadores[1].nombre;
}
cout<<"GANADOR: "<< ganador  <<endl;

Sleep(5000);

   rlutil::cls();
   main();





}

*/


void borrarCin()
{

    rlutil::locate(30,28);
    cout<<"   ";


}


void borrarCout()
{


    rlutil::locate(30,25);
    cout<<"                                                         ";



}


    /// decide quien empieza primero la fase final

 void turnoJugadores(int& primerJugador,int& segundoJugador, jugadores vJugadores[2]){

    int contJugadorUno =0;
    int contJugadorDos =0;


   /// recorremos el vector buscando quien tiene mas estatuillas ganadas
    for(int i=0;i<5;i++){

        if(vJugadores[0].vEstatuillasObtenidas[i]){

            contJugadorUno++;
        }


        if(vJugadores[1].vEstatuillasObtenidas[i]){

            contJugadorDos++;
        }


    }

    if(contJugadorUno > contJugadorDos){
        primerJugador=0;
        segundoJugador =1;
    }else{
        primerJugador = 1;
        segundoJugador = 0;
    }

    }








/// evalua los criterios para ganar las estatuillas con TRES dados


void evaluarSeleccionTresDados(int seleccion,int jugadorActual,jugadores vJugadores[2],estatuas& estatuillas)
{



    /// carga en las variables los 3 dados del jugador actual

    int dadoUno,dadoDos,dadoTres;

    dadoUno = vJugadores[jugadorActual].dados[0];
    dadoDos = vJugadores[jugadorActual].dados[1];
    dadoTres = vJugadores[jugadorActual].dados[2];


    /// reconoce al jugador actual y a su rival
    int jugadorRival;

    if(jugadorActual == 0)
    {

        jugadorRival = 1;
        llenarVectorDadosJugadorDos(vJugadores);

    }
    if(jugadorActual == 1)
    {

        jugadorRival = 0;
        llenarVectorDadosJugadorUno(vJugadores);
    }



    /// evalua si se ganó o no la estatuilla, cambia el estado de estatuillas del jugador, y estatuillas globales
    ///  lanza un mensaje si gano o no la estatuilla



    switch(seleccion)
    {

    case 0:

        if(cangrejo_tres(dadoUno,dadoDos,dadoTres))
        {
            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<" Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
            Sleep(1000);

            borrarCout();
            rlutil::locate(30,25);

            cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza Un dado";
            Sleep(2000);

            borrarCout();
            rlutil::locate(30,25);
            lanzarUnDadoDiezCaras(vJugadores,jugadorRival);

            borrarCout();
            vJugadores[jugadorActual].puntos -= vJugadores[jugadorRival].dados[0];
            rlutil::locate(30,25);
            cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0]<< " puntos "<<" Al jugador "<<vJugadores[jugadorActual].nombre;

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


        if(hormiga_tres(dadoUno,dadoDos,dadoTres))
        {
            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
            Sleep(1000);

             borrarCout();
            rlutil::locate(30,25);

            cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza dos dados";
            Sleep(2000);

            borrarCout();
            rlutil::locate(30,25);
            lanzarDosDadosDiezCaras(vJugadores,jugadorRival);

            borrarCout();
            vJugadores[jugadorActual].puntos -= ( vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1]);
            rlutil::locate(30,25);
            cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1] << " puntos "<<" Al jugador "<<vJugadores[jugadorActual].nombre;

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

        if(medusa_tres(dadoUno,dadoDos,dadoTres))
        {


            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
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


        if(aguila_tres(dadoUno,dadoDos,dadoTres))
        {


            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
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



void evaluarSeleccionDosDados(int seleccion,int jugadorActual,jugadores vJugadores[2],estatuas& estatuillas)
{



    /// carga en las variables los 3 dados del jugador actual

    int dadoUno,dadoDos;

    dadoUno = vJugadores[jugadorActual].dados[0];
    dadoDos = vJugadores[jugadorActual].dados[1];


    /// reconoce al jugador actual y a su rival
    /// se llenan sus respectivos vectores de dados
    int jugadorRival;

    if(jugadorActual == 0)
    {

        jugadorRival = 1;
        llenarVectorDadosJugadorDos(vJugadores);

    }
    if(jugadorActual == 1)
    {

        jugadorRival = 0;
        llenarVectorDadosJugadorUno(vJugadores);
    }



    /// evalua si se ganó o no la estatuilla, cambia el estado de estatuillas del jugador, y estatuillas globales
    ///  lanza un mensaje si gano o no la estatuilla


    switch(seleccion)
    {

    case 0:

        if(cangrejo(dadoUno,dadoDos))
        {
            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<" Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
            Sleep(1000);

            ///


            borrarCout();
            rlutil::locate(30,25);

            cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza Un dado";
            Sleep(2000);

            borrarCout();
            rlutil::locate(30,25);
            lanzarUnDadoDiezCaras(vJugadores,jugadorRival);

            borrarCout();
            vJugadores[jugadorActual].puntos -= vJugadores[jugadorRival].dados[0];
            rlutil::locate(30,25);
            cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0]<< " puntos "<<" Al jugador "<<vJugadores[jugadorActual].nombre;

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


        if(hormiga(dadoUno,dadoDos))
        {
            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
            Sleep(1000);

             borrarCout();
            rlutil::locate(30,25);

            cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza dos dados";
            Sleep(2000);

            borrarCout();
            rlutil::locate(30,25);
            lanzarDosDadosDiezCaras(vJugadores,jugadorRival);

            borrarCout();
            vJugadores[jugadorActual].puntos -= ( vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1]);
            rlutil::locate(30,25);
            cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1] << " puntos "<<" Al jugador "<<vJugadores[jugadorActual].nombre;

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

        if(medusa(dadoUno,dadoDos))
        {


            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
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


        if(aguila(dadoUno,dadoDos))
        {


            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
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


        if(salamandra(dadoUno,dadoDos))
        {


            vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
            estatuillas.vEstatuillasDisponibles[seleccion] = false;


            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
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




/// Lanza 2 veces si el rival tiene la maldicion del aguila

void evaluarMaldicionAguila(jugadores vJugadores[2])
{

    if(vJugadores[0].vEstatuillasObtenidas[3])
    {
        vJugadores[1].rondas = 2;
    }
    if(vJugadores[1].vEstatuillasObtenidas[3])
    {
        vJugadores[0].rondas = 2;
    }
}





/// Lanza 3 dados si el rival tiene la maldicion de la salamandra

bool evaluarMaldicionSalamandra(jugadores vJugadores[2],int nroJugadorActual)
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

        lanzarTresDadosDiezCaras(vJugadores,nroJugadorActual);
        return true;
    }
    else
    {
        lanzarDosDadosDiezCaras(vJugadores,nroJugadorActual);
        return false;
    }

}














/// Pide nombre a cada jugador y lo almacena

void pedirDatos(jugadores vJugadores[2])
{

    for(int x=0; x<2; x++)
    {


        cout << "Nombre del jugador "<<x+1<<endl;


        cin >> vJugadores[x].nombre;

    }

}


/// muestra estatuillas disponibles para todos

void estatuillasDisponibles(estatuas& est)
{

    int posx = 1, posy = 5;

    for(int i=0; i<5; i++)
    {

        posy+=3;

        if(est.vEstatuillasDisponibles[i])
        {



            rlutil::locate(posx,posy);
            cout<<est.vEstatuillas[i];
        }
        else
        {


            rlutil::locate(posx,posy);
            cout<<"              ";


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
        else
        {

            rlutil::locate(datoEstatuillaX += 10,3);
            cout<<"               ";

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
        else
        {

            rlutil::locate(datoEstatuillaX += 10,3);
            cout<<"               ";


        }


    }

}





///CARGA VECTORES DE LOS DADOS
void llenarVectorDadosJugadorUno(jugadores vJugadores[2])
{


    srand(time(0));

    for(int i=0; i<5; i++)
    {

        vJugadores[0].dados[i]= 1+ (rand()%10);
    }

}

void llenarVectorDadosJugadorDos(jugadores vJugadores[2])
{


    srand(time(0));

    for(int i=0; i<5; i++)
    {

        vJugadores[1].dados[i]= 1+ (rand()%10);
    }

}







/// devuelve false si ya no hay estatuillas disponibles en juego

bool terminarExpedicion(estatuas& estatuillas)
{
    int cont = 0;

    for(int i=0; i<5; i++)
    {

        if(estatuillas.vEstatuillasDisponibles[i] == false)

            cont++;
    }

    if(cont == 5)
    {

        return false;

    }
    return true;
}


/// Selecciona estatuilla
/// retorna el indice de la estatuilla seleccionada

int seleccionarEstatuilla(estatuas& estatuillas)
{

    bool fin = false;

    while(fin != true)
    {

        int seleccion;



        borrarCin();
        borrarCout();
        rlutil::locate(30,25);
        cout<<"Seleccione una estatuilla";
        rlutil::locate(30,28);
        cin>>seleccion;

        switch(seleccion)
        {

        case 1:

            if(estatuillas.vEstatuillasDisponibles[0])
            {

                borrarCout();
                rlutil::locate(30,25);
                cout<<"Seleccionaste la estatuilla : "<<estatuillas.vEstatuillas[0];
                Sleep(1000);
                borrarCout();
                borrarCin();
                return 0;

            }
            else if(estatuillas.vEstatuillasDisponibles[0]==false)
            {

                borrarCout();
                rlutil::locate(30,25);
                cout<<"estatuilla no disponible";
                Sleep(1000);

                borrarCout();
                rlutil::locate(30,25);
                cout<<"seleccione otra";

            }

            break;

        case 2:

            if(estatuillas.vEstatuillasDisponibles[1])
            {

                borrarCout();
                rlutil::locate(30,25);
                cout<<"Seleccionaste la estatuilla : "<<estatuillas.vEstatuillas[1];
                Sleep(1000);
                borrarCout();
                borrarCin();
                return 1;

            }
            else if(estatuillas.vEstatuillasDisponibles[1]==false)
            {

                borrarCout();
                rlutil::locate(30,25);
                cout<<"estatuilla no disponible";
                Sleep(1000);
                borrarCout();
                rlutil::locate(30,25);
                cout<<"seleccione otra";

            }



            break;

        case 3:

            if(estatuillas.vEstatuillasDisponibles[2])
            {

                borrarCout();
                rlutil::locate(30,25);
                cout<<"Seleccionaste la estatuilla : "<<estatuillas.vEstatuillas[2];
                Sleep(1000);
                borrarCout();
                borrarCin();
                return 2;

            }
            else if(estatuillas.vEstatuillasDisponibles[2]==false)
            {

                borrarCout();
                rlutil::locate(30,25);
                cout<<"estatuilla no disponible";
                Sleep(1000);
                borrarCout();
                rlutil::locate(30,25);
                cout<<"seleccione otra";

            }



            break;


        case 4:


            if(estatuillas.vEstatuillasDisponibles[3])
            {

                borrarCout();
                rlutil::locate(30,25);
                cout<<"Seleccionaste la estatuilla : "<<estatuillas.vEstatuillas[3];
                Sleep(1000);
                borrarCout();
                borrarCin();
                return 3;

            }
            else if(estatuillas.vEstatuillasDisponibles[3]==false)
            {

                borrarCout();
                rlutil::locate(30,25);
                cout<<"estatuilla no disponible";
                Sleep(1000);
                borrarCout();
                rlutil::locate(30,25);
                cout<<"seleccione otra";

            }


            break;

        case 5:


            if(estatuillas.vEstatuillasDisponibles[4])
            {

                borrarCout();
                rlutil::locate(30,25);
                cout<<"Seleccionaste la estatuilla : "<<estatuillas.vEstatuillas[4];
                Sleep(1000);
                borrarCout();
                borrarCin();
                return 4;

            }
            else if(estatuillas.vEstatuillasDisponibles[4]==false)
            {


                borrarCout();
                rlutil::locate(30,25);
                cout<<"estatuilla no disponible";
                Sleep(1000);
                borrarCout();
                rlutil::locate(30,25);
                cout<<"seleccione otra";
                Sleep(1000);

            }


            break;

        default:

            borrarCout();
            rlutil::locate(30,25);
            cout<<"Ingreso no valido, Seleccione otra";
            Sleep(1000);

            break;


        }



    }
}

///Lan dados


void lanzarUnDadoDiezCaras(jugadores vJugadores[2],int nroJugador)
{

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




/// juega hasta que gane alguno si gana el 2 se intercambian nombres

void jugarPorTurno(jugadores vJugadores[2], estatuas& estatuillas)
{

    bool salir = false;

    while(salir != true)
    {


/// tira jugador 1

        system("cls");
        mesa();
        mostrarDatosJugadorUno(vJugadores);
        llenarVectorDadosJugadorUno(vJugadores);
        lanzarUnDadoDiezCaras(vJugadores,0);




        /// tiempo intermedio
        Sleep(2000);


        /// tira jugador 2

        system("cls");
        mesa();
        mostrarDatosJugadorDos(vJugadores);
        llenarVectorDadosJugadorDos(vJugadores);
        lanzarUnDadoDiezCaras(vJugadores,1);


        Sleep(2000);



        /// si gana el jugador 1
        if(vJugadores[0].dados[0]<vJugadores[1].dados[0])
        {

            salir = true;
            system("cls");
        }
        /// si gana el jugador 2 intercambian nombres
        else if(vJugadores[1].dados[0]<vJugadores[0].dados[0])
        {

            string nAux = vJugadores[0].nombre;

            vJugadores[0].nombre = vJugadores[1].nombre;
            vJugadores[1].nombre = nAux;

            salir = true;
            system("cls");
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
        return true;
    }
    else
    {
        return false;
    }
}


bool hormiga_tres(int d1, int d2, int d3)
{
    if((d1<5 && d2<5) || (d1<5 && d3<5) || (d2<5 && d3<5))
    {
        return true;
    }
    return false;
}


bool medusa_tres(int d1, int d2, int d3)
{
    int r=d1+d2, r1=d1+d3, r2=d2+d3;
    if(r==7 || r1==7 || r2==7)
    {
        return true;
    }
    return false;
}


bool aguila_tres(int d1, int d2, int d3)
{
    if((d1==1 && d2==10) || (d1==10 && d2==1) || (d1==1 && d3==10) || (d1==10 && d3==1) || (d2==1 && d3==10) || (d2==10 && d3==1))
    {
        return true;
    }
    return false;
}


