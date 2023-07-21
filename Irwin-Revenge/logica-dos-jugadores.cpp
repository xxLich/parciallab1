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
#include "Menu.h"
#include "lab.h"

using namespace std;

/// Estadisticas


void estadisticas(int posX,int posY,jugadores[]);
void nombreJuego(int,int);
void Jugadores(int,int,jugadores[]);




void estadisticas(int posX,int posY,jugadores vJugadores[2])
{

    //Suma los puntos totales

    vJugadores[0].puntos=vJugadores[0].PuntosEst+vJugadores[0].PuntosEstMas+vJugadores[0].PuntosGan+vJugadores[0].PuntosGanMas+
                         vJugadores[0].PuntosEstMenos+vJugadores[0].PuntosLanz+vJugadores[0].PuntosCangrejo+vJugadores[0].PuntosHormiga;

    vJugadores[1].puntos=vJugadores[1].PuntosEst+vJugadores[1].PuntosEstMas+vJugadores[1].PuntosGan+vJugadores[1].PuntosGanMas+
                         vJugadores[1].PuntosEstMenos+vJugadores[1].PuntosLanz+vJugadores[1].PuntosCangrejo+vJugadores[1].PuntosHormiga;


    nombreJuego(1,1);
    Jugadores(1,1,vJugadores);

    rlutil::anykey("Presione una tecla para volver al menu");
    rlutil::cls();
}

/*

bool SAC(jugadores vJugadores[2],int nroJugador)
        {

            bool salamandra = vJugadores[nroJugador].vEstatuillasObtenidas[4];
            bool aguila = vJugadores[nroJugador].vEstatuillasObtenidas[3];
            bool cangrejo = vJugadores[nroJugador].vEstatuillasObtenidas[0];

            if(salamandra && aguila && cangrejo){

                return true;
            }

            return false;

        }


*/



void nombreJuego(int posX,int posY)
{

    cout<<"                           Irwin Revenge - Estadistica del juego"                              <<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;

}
void Jugadores(int posX,int posY,jugadores vJugadores[2])
{

    cout<<"HITO";
    rlutil::locate(31,4);
    cout<<vJugadores[0].nombre;
    rlutil::locate(51,4);
    cout<<vJugadores[1].nombre<<endl;

    cout<<"----------------------------------------------------------------------------------------------"<<endl;

    cout<<"Estatuilla";
    rlutil::locate(32,6);
    cout<<vJugadores[0].PuntosEst;
    rlutil::locate(52,6);
    cout<<vJugadores[1].PuntosEst<<endl<<endl;

    cout<<"Estatuilla++";
    rlutil::locate(32,8);
    cout<<vJugadores[0].PuntosEstMas;
    rlutil::locate(52,8);
    cout<<vJugadores[1].PuntosEstMas<<endl<<endl;

    cout<<"Descuento maldicion cangrejo";
    rlutil::locate(32,10);
    cout<<vJugadores[0].PuntosCangrejo;
    rlutil::locate(52,10);
    cout<<vJugadores[1].PuntosCangrejo<<endl<<endl;

    cout<<"Descuento maldicion hormiga";
    rlutil::locate(32,12);
    cout<<vJugadores[0].PuntosHormiga;
    rlutil::locate(52,12);
    cout<<vJugadores[1].PuntosHormiga<<endl<<endl;

    cout<<"Ganador";
    rlutil::locate(32,14);
    cout<<vJugadores[0].PuntosGan;
    rlutil::locate(52,14);
    cout<<vJugadores[1].PuntosGan<<endl<<endl;

    cout<<"Ganador++";
    rlutil::locate(32,16);
    cout<<vJugadores[0].PuntosGanMas;
    rlutil::locate(52,16);
    cout<<vJugadores[1].PuntosGanMas<<endl<<endl;

    cout<<"Est --";
    rlutil::locate(32,18);
    cout<<vJugadores[0].PuntosEstMenos;
    rlutil::locate(52,18);
    cout<<vJugadores[1].PuntosEstMenos<<endl<<endl;

    cout<<"Lanzamiento";
    rlutil::locate(32,20);
    cout<<vJugadores[0].PuntosLanz;
    rlutil::locate(52,20);
    cout<<vJugadores[1].PuntosLanz<<endl;


/*

    cout<<"S-A-C";
    if(SAC(vJugadores,0))
    {

        vJugadores[0].puntos+=20;
        rlutil::locate(32,22);
        cout<<20;
        rlutil::locate(52,22);
        cout<<0<<endl;

    }

    if(SAC(vJugadores,1))
    {

        vJugadores[1].puntos+=20;
        rlutil::locate(32,22);
        cout<<20;
        rlutil::locate(52,22);
        cout<<0<<endl;

    }

*/

            cout<<"----------------------------------------------------------------------------------------------"<<endl;

            cout<<"TOTAL";
            rlutil::locate(32,22);
            cout<<vJugadores[0].puntos;
            rlutil::locate(52,22);
            cout<<vJugadores[1].puntos <<endl;

            cout<<"----------------------------------------------------------------------------------------------"<<endl;

            string ganador;

            if(vJugadores[0].puntos>vJugadores[1].puntos)
            {
                ganador=vJugadores[0].nombre;
            }
            else
            {

                ganador = vJugadores[1].nombre;
            }
            cout<<"GANADOR: "<< ganador  <<endl<<endl;

        }


        void borrarCin()
        {
            rlutil::locate(30,28);
            cout<<"     ";
            rlutil::locate(1,29);
            cout<<"     ";
            rlutil::locate(1,30);
            cout<<"     ";
        }


        void borrarCout()
        {
            rlutil::locate(30,25);
            cout<<"                                                              ";
            rlutil::locate(30,26);
            cout<<"                                                              ";
            rlutil::locate(30,27);
            cout<<"                                                              ";
        }



/// decide quien empieza primero la fase final

        void turnoJugadores(int& primerJugador,int& segundoJugador, jugadores vJugadores[2])
        {

            int contJugadorUno =0;
            int contJugadorDos =0;


            /// recorremos el vector buscando quien tiene mas estatuillas ganadas
            for(int i=0; i<5; i++)
            {

                if(vJugadores[0].vEstatuillasObtenidas[i])
                {

                    contJugadorUno++;
                }


                if(vJugadores[1].vEstatuillasObtenidas[i])
                {

                    contJugadorDos++;
                }


            }

            if(contJugadorUno > contJugadorDos)
            {
                primerJugador=0;
                segundoJugador =1;
            }
            else
            {
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

                //Se usa un contador para saber si es la primera vez que se jugara por la estampilla
                vJugadores[jugadorActual].intentoCangrejo++;

                if(cangrejo_tres(dadoUno,dadoDos,dadoTres))
                {
                    vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
                    estatuillas.vEstatuillasDisponibles[seleccion] = false;


                    borrarCout();
                    rlutil::locate(30,25);
                    cout<<" Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
                    PuntosExpedicion(vJugadores[jugadorActual].PuntosEst, vJugadores[jugadorActual].PuntosEstMas, vJugadores[jugadorRival].PuntosEstMenos, vJugadores[jugadorActual].intentoCangrejo);
                    Sleep(1000);

                    borrarCout();
                    rlutil::locate(30,25);

                    cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza Un dado";
                    Sleep(2000);

                    borrarCout();
                    rlutil::locate(30,25);
                    lanzarUnDadoDiezCaras(vJugadores,jugadorRival);

                    borrarCout();
                    vJugadores[jugadorActual].PuntosCangrejo -= vJugadores[jugadorRival].dados[0];
                    rlutil::locate(30,25);
                    cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0]<< " puntos "<<" al jugador "<<vJugadores[jugadorActual].nombre;

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
                    cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
                    PuntosExpedicion(vJugadores[jugadorActual].PuntosEst, vJugadores[jugadorActual].PuntosEstMas, vJugadores[jugadorRival].PuntosEstMenos, vJugadores[jugadorActual].intentoHormiga);
                    Sleep(1000);

                    borrarCout();
                    rlutil::locate(30,25);

                    cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza dos dados";
                    Sleep(2000);

                    borrarCout();
                    rlutil::locate(30,25);
                    lanzarDosDadosDiezCaras(vJugadores,jugadorRival);

                    borrarCout();
                    vJugadores[jugadorActual].PuntosHormiga -= ( vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1]);
                    rlutil::locate(30,25);
                    cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1] << " puntos "<<" al jugador "<<vJugadores[jugadorActual].nombre;

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
                    cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
                    PuntosExpedicion(vJugadores[jugadorActual].PuntosEst, vJugadores[jugadorActual].PuntosEstMas, vJugadores[jugadorRival].PuntosEstMenos, vJugadores[jugadorActual].intentoMedusa);
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
                    cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
                    PuntosExpedicion(vJugadores[jugadorActual].PuntosEst, vJugadores[jugadorActual].PuntosEstMas, vJugadores[jugadorRival].PuntosEstMenos, vJugadores[jugadorActual].intentoAguila);
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
                vJugadores[jugadorActual].intentoCangrejo++;

                if(cangrejo(dadoUno,dadoDos))
                {
                    vJugadores[jugadorActual].vEstatuillasObtenidas[seleccion]= true;
                    estatuillas.vEstatuillasDisponibles[seleccion] = false;


                    borrarCout();
                    rlutil::locate(30,25);
                    cout<<" Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
                    PuntosExpedicion(vJugadores[jugadorActual].PuntosEst, vJugadores[jugadorActual].PuntosEstMas, vJugadores[jugadorRival].PuntosEstMenos, vJugadores[jugadorActual].intentoCangrejo);
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
                    vJugadores[jugadorActual].PuntosCangrejo -= vJugadores[jugadorRival].dados[0];
                    rlutil::locate(30,25);
                    cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0]<< " puntos "<<" al jugador "<<vJugadores[jugadorActual].nombre;

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
                    cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
                    PuntosExpedicion(vJugadores[jugadorActual].PuntosEst, vJugadores[jugadorActual].PuntosEstMas, vJugadores[jugadorRival].PuntosEstMenos, vJugadores[jugadorActual].intentoHormiga);
                    Sleep(1000);

                    borrarCout();
                    rlutil::locate(30,25);

                    cout<<"El jugador "<<vJugadores[jugadorRival].nombre<<" lanza dos dados";
                    Sleep(2000);

                    borrarCout();
                    rlutil::locate(30,25);
                    lanzarDosDadosDiezCaras(vJugadores,jugadorRival);

                    borrarCout();
                    vJugadores[jugadorActual].PuntosHormiga -= ( vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1]);
                    rlutil::locate(30,25);
                    cout<<"Se le descontaron "<<vJugadores[jugadorRival].dados[0] + vJugadores[jugadorRival].dados[1] << " puntos "<<" al jugador "<<vJugadores[jugadorActual].nombre;

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
                    cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
                    PuntosExpedicion(vJugadores[jugadorActual].PuntosEst, vJugadores[jugadorActual].PuntosEstMas, vJugadores[jugadorRival].PuntosEstMenos, vJugadores[jugadorActual].intentoMedusa);
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
                    cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
                    PuntosExpedicion(vJugadores[jugadorActual].PuntosEst, vJugadores[jugadorActual].PuntosEstMas, vJugadores[jugadorRival].PuntosEstMenos, vJugadores[jugadorActual].intentoAguila);
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
                    cout<<"Ganaste la estatuilla :"<< estatuillas.vEstatuillas[seleccion];
                    PuntosExpedicion(vJugadores[jugadorActual].PuntosEst, vJugadores[jugadorActual].PuntosEstMas, vJugadores[jugadorRival].PuntosEstMenos, vJugadores[jugadorActual].intentoSalamandra);
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
            for (int x = 0; x < 2; x++)
            {


                rlutil::cls();

                rlutil::setColor(rlutil::LIGHTBLUE);
                rlutil::locate(40, 10);
                cout << "Jugador " << x + 1 << endl;

                rlutil::setColor(rlutil::WHITE);
                rlutil::locate(40, 12);
                cout << "Ingrese su nombre: ";

                rlutil::locate(40, 14);
                cin>> vJugadores[x].nombre;
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

            rlutil::locate(3,2);
            cout<<"            ";

            rlutil::locate(3,2);
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

            rlutil::locate(3,2);
            cout<<"             ";

            rlutil::locate(3,2);
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

///CARGA VECTORES DE LOS DADOS DE 6 CARAS.
        void llenarVectorDadosJugadorUnoFF(jugadores vJugadores[2])
        {


            srand(time(0));

            for(int i=0; i<5; i++)
            {

                vJugadores[0].dados[i]= 1+ (rand()%6);
            }

        }

        void llenarVectorDadosJugadorDosFF(jugadores vJugadores[2])
        {


            srand(time(0));

            for(int i=0; i<5; i++)
            {

                vJugadores[1].dados[i]= 1+ (rand()%6);
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

///

        int EstatuillasCero(bool vect[5])
        {
            int cont=0;
            for(int x=0; x<5; x++)
            {
                if(vect[x])
                {
                    cont++;
                }
            }
            if(cont==0)
            {
                return 1;
            }
            return 0;

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

            if((v1!=0 && v2==0) || (v1==0 && v2!=0) || (v1==0 && v3!=0) || (v1!=0 && v3==0) || (v2==0 && v3!=0) || (v2!=0 && v3==0))
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





//FUNCION PARA OBTENER LOS PUNTOS DE LA FASE DE EXPEDICION

        void PuntosExpedicion(int& cont, int& contmas, int& contmenos, int intento)
        {
            if(intento==1)
            {
                contmas+=10;
            }
            else
            {
                cont+=5;
            }
            contmenos-=3;
        }

//FUNCIONES PARA SABER SI SE GANO LA FASE FINAL

//ESCALERA COMUN




        bool GanarFF(jugadores vJugadores[2],int jugadorActual)
        {

            int d1=vJugadores[jugadorActual].dados[0],
                d2=vJugadores[jugadorActual].dados[1],
                d3=vJugadores[jugadorActual].dados[2],
                d4=vJugadores[jugadorActual].dados[3],
                d5=vJugadores[jugadorActual].dados[4];



            if((d1!=d2 && d1!=d3 && d1!=d4 && d1!=d5 && d2!=d3 && d2!=d4 && d2!=d5 && d3!=d4 && d3!=d5 && d4!=d5)&&(d1==2 || d2==2 || d3==2 || d4==2 || d5==2)&&
                    (d1==3 || d2==3 || d3==3 || d4==3 || d5==3)&&(d1==4 || d2==4 || d3==4 || d4==4 || d5==4)&&(d1==5 || d2==5 || d3==5 || d4==5 || d5==5))
            {
                return 1;
            }
            return 0;
        }

//ESCALERA CORTA (SALAMANDRA)

        bool GanarFFS(jugadores vJugadores[2],int jugadorActual)
        {

            int dados[5];

/// llenamos vector de dados auxiliar
            for(int i=0; i<5; i++)
            {

                dados[i]=vJugadores[jugadorActual].dados[i];

            }

/// ordenar de menor a mayor
            int aux;

            for(int j=0; j<5; j++)
            {
                for(int i=0; i<5-1; i++)
                {

                    if(dados[i]>dados[i+1])
                    {

                        aux = dados[i+1];
                        dados[i+1]=dados[i];
                        dados[i]= aux;

                    }
                }
            }


/// verificar si es escalera

            int contEscalera=0;

            for(int i=0; i<5-1; i++)
            {

                if(dados[i+1]== dados[i]+1)
                {
                    contEscalera++;
                }
                else
                {

                    break;

                }
            }

            if(contEscalera==3)
            {

                return true;

            }
            else
            {

                return false;
            }


        }






//ESCALERA TIPO MEDUSA

        bool GanarFFM(jugadores vJugadores[2],int jugadorActual)
        {

            int d1=vJugadores[jugadorActual].dados[0],
                d2=vJugadores[jugadorActual].dados[1],
                d3=vJugadores[jugadorActual].dados[2],
                d4=vJugadores[jugadorActual].dados[3],
                d5=vJugadores[jugadorActual].dados[4];

            if(d1==d2 && d2==d3 && d3==d4 && d4==d5)
            {
                return true;
            }
            return false;
        }

        void FaseFinal(jugadores vJugadores[2],bool& FinFF,bool& cero, int jugadorActual, int& contHormiga,int NumH)
        {

            if(FinFF== false)
            {

                int dado1,dado2,dado3,dado4,dado5;
                bool BendHormiga,BendMedusa,BendAguila,BendSalamandra;


                /// llenamos variables con valores del vJugadores

                dado1 = vJugadores[jugadorActual].dados[0];
                dado2 = vJugadores[jugadorActual].dados[1];
                dado3 = vJugadores[jugadorActual].dados[2];
                dado4 = vJugadores[jugadorActual].dados[3];
                dado5 = vJugadores[jugadorActual].dados[4];

                BendHormiga = vJugadores[jugadorActual].vEstatuillasObtenidas[1];
                BendMedusa = vJugadores[jugadorActual].vEstatuillasObtenidas[2];
                BendAguila = vJugadores[jugadorActual].vEstatuillasObtenidas[3];
                BendSalamandra  = vJugadores[jugadorActual].vEstatuillasObtenidas[4];






                ///NumA sera el numero que eligio el portador de la bendicion
                int NumA;



                // Hormiga = Eleccion de dado para cambiar valor (por BH)
                // opcionAguiladado = lo mismo que Hormiga
                int opcionDadoHormiga;




                int opcionDadoAguila;
                // Horm = Eleccion 1 o 2.
                int Horm;


                // Opcion de numero
                int opcionAguila;





                ///serepiteBH es por si se puso un numero incorrecto
                bool serepiteBH;
                bool serepitehorm;
                bool serepiteaguila;




                /// elige 1 solo valor con el cual se puede intercambiar el valor de un dado por este



                /// jugador actual tiene hormiga
                if(BendHormiga)
                {



                    rlutil::locate(30,25);
                    cout << "Desea cambiar el valor de algun dado por el numero: " << NumH << endl;
                    rlutil::locate(30,26);
                    cout << "     1     - Si" << endl;
                    rlutil::locate(30,27);
                    cout << "     2     - No" << endl;

                    /// Usamos un do while interno que nos servira por si el jugador escoje mal un numero asi tiene la oportunidad de elegir bien.

                    do
                    {



                        /// Horm = Eleccion 1 o 2.
                        /// opcionDadoHormiga = Eleccion de dado para cambiar valor (por BH)


                        rlutil::locate(30,28);
                        cin >> Horm;
                        borrarCout();
                        borrarCin();

                        switch (Horm)
                        {
                        case 1:
                            rlutil::locate(30, 25);
                            cout << "Que dado desea cambiar (1 al 5)" << endl;
                            rlutil::locate(30, 26);
                            cout << "Dado 1      Dado 2       Dado 3"<< endl;
                            rlutil::locate(30, 27);
                            cout << "      Dado 4       Dado 5"<< endl;
                            rlutil::locate(30,28);

                            cin >> opcionDadoHormiga;



                            borrarCout();
                            borrarCin();


                            switch (opcionDadoHormiga)
                            {
                            case 1:

                                vJugadores[jugadorActual].dados[0] = NumH;
                                serepitehorm=false;

                                ///serepitehorm si es falso saldra del do whilee interno.

                                break;
                            case 2:

                                vJugadores[jugadorActual].dados[1] = NumH;
                                serepitehorm=false;
                                break;
                            case 3:

                                vJugadores[jugadorActual].dados[2] = NumH;
                                serepitehorm=false;
                                break;
                            case 4:

                                vJugadores[jugadorActual].dados[3] = NumH;
                                serepitehorm=false;
                                break;
                            case 5:

                                vJugadores[jugadorActual].dados[4] = NumH;
                                serepitehorm=false;
                                break;


                            default:
                                rlutil::locate(35, 28);
                                cout << "(opcion incorrecta, elegi nuevamente)" << endl;
                                Sleep(1500);

                                rlutil::locate(30,25);
                                cout << "Desea cambiar el valor de algun dado por el numero: " << NumH << endl;
                                rlutil::locate(30,26);
                                cout << "     1     - Si" << endl;
                                rlutil::locate(30,27);
                                cout << "     2     - No" << endl;

                                serepitehorm=true;

                                ///serepitehorm es true, por lo tanto cumple con el requisito del do while, entonces se repite vuelta, esto es porque eligio mal una opcion.

                                break;

                            }



                            lanzarCincoDadosSeisCaras(vJugadores,jugadorActual);


                            borrarCout();
                            rlutil::locate(30,25);
                            rlutil::anykey("pulse una tecla para continuar");





                            break;

                        /// si no quiere cambiar un numero , sale del do while
                        case 2:



                            serepitehorm=false;
                            break;



                        default:
                            rlutil::locate(35, 28);
                            cout << "(opcion equivocada, elegi nuevamente)" << endl;
                            Sleep(1500);

                            rlutil::locate(30,25);
                            cout << "Desea cambiar el valor de algun dado por el numero: " << NumH << endl;
                            rlutil::locate(30,26);
                            cout << "     1     - Si" << endl;
                            rlutil::locate(30,27);
                            cout << "     2     - No" << endl;

                            serepitehorm=true;
                        }

                    }
                    while(serepitehorm==true);

                }


                ///Pregunto por si el jugador tiene la bendicion aguila
                /// si tiene aguila elige la posicion de un dado para cambiar su valor


                if(BendAguila)
                {
                    rlutil::locate(30,25);
                    cout << "Desea cambiar el valor de algun dado?"<< endl;
                    rlutil::locate(30,26);
                    cout << "     1     - Si" << endl;
                    rlutil::locate(30,27);
                    cout << "     2     - No" << endl;

                    /// Usamos un do while interno que nos servira por si el jugador escoje mal un numero asi tiene la oportunidad de elegir bien (NumA = variable para la eleccion).

                    do
                    {
                        rlutil::locate(30,28);

                        /// es 1 o 2 , variable para elegir eleccion de dado
                        cin >> NumA;
                        borrarCin();
                        borrarCout();


                        switch (NumA)
                        {

                        case 1:
                            rlutil::locate(30, 25);
                            cout << "Que dado desea cambiar (1 al 5)" << endl;
                            rlutil::locate(30, 26);
                            cout << "Dado 1      Dado 2       Dado 3"<< endl;
                            rlutil::locate(30, 27);
                            cout << "      Dado 4       Dado 5"<< endl;
                            rlutil::locate(30,28);

                            /// que dado va a cambiar
                            cin >> opcionDadoAguila;
                            borrarCout();
                            borrarCin();


                            switch (opcionDadoAguila)
                            {
                            case 1:

                                rlutil::locate(30,25);
                                cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                rlutil::locate(30,28);

                                /// valor por el cual vamos a cambiar un dado a eleccion
                                cin >> opcionAguila;
                                borrarCin();
                                borrarCout();

                                ///Se cambia el valor del dado por un valor de preferencia.

                                if(opcionAguila>0 && opcionAguila<7)
                                {
                                    vJugadores[jugadorActual].dados[0] = opcionAguila;
                                    serepiteaguila=false;
                                }
                                else
                                {
                                    rlutil::locate(30,27);
                                    cout << "opcion equivocada" << endl;
                                    Sleep(1500);

                                    serepiteaguila=true;
                                    ///Si elegis mal entonces por medio de serepiteaguila=true vuelve a elegir un dado
                                }
                                break;
                            case 2:
                                rlutil::locate(30,25);
                                cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                rlutil::locate(30,28);
                                cin >> opcionAguila;
                                borrarCin();
                                borrarCout();

                                if(opcionAguila>0 && opcionAguila<7)
                                {
                                    vJugadores[jugadorActual].dados[1] = opcionAguila;
                                    serepiteaguila=false;
                                }
                                else
                                {
                                    rlutil::locate(30,27);
                                    cout << "opcion equivocada" << endl;
                                    Sleep(1500);

                                    serepiteaguila=true;
                                }
                                break;
                            case 3:
                                borrarCin();
                                borrarCout();
                                rlutil::locate(30,25);
                                cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                rlutil::locate(30,28);
                                cin >> opcionAguila;
                                borrarCin();
                                borrarCout();

                                if(opcionAguila>0 && opcionAguila<7)
                                {
                                    vJugadores[jugadorActual].dados[2] = opcionAguila;
                                    serepiteaguila=false;
                                }
                                else
                                {
                                    rlutil::locate(30,27);
                                    cout << "opcion equivocada" << endl;
                                    Sleep(1500);

                                    serepiteaguila=true;
                                }
                                break;
                            case 4:
                                rlutil::locate(30,25);
                                cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                rlutil::locate(30,28);
                                cin >> opcionAguila;
                                borrarCin();
                                borrarCout();

                                if(opcionAguila>0 && opcionAguila<7)
                                {
                                    vJugadores[jugadorActual].dados[3] = opcionAguila;
                                    serepiteaguila=false;
                                }
                                else
                                {
                                    rlutil::locate(30,27);
                                    cout << "opcion equivocada" << endl;
                                    Sleep(1500);

                                    serepiteaguila=true;
                                }
                                break;
                            case 5:
                                rlutil::locate(30,25);
                                cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                rlutil::locate(30,26);
                                cin >> opcionAguila;
                                borrarCin();
                                borrarCout();

                                if(opcionAguila>0 && opcionAguila<7)
                                {
                                    vJugadores[jugadorActual].dados[4] = opcionAguila;
                                    serepiteaguila=false;
                                }
                                else
                                {
                                    rlutil::locate(30,27);
                                    cout << "opcion equivocada" << endl;
                                    Sleep(1500);

                                    serepiteaguila=true;
                                }
                                break;

                            default:
                                cout << "opcion equivocada" << endl;
                                Sleep(1500);
                                serepiteaguila=true;
                                break;
                            }


                            lanzarCincoDadosSeisCaras(vJugadores,jugadorActual);



                            borrarCout();
                            rlutil::locate(30,25);
                            rlutil::anykey("pulse una tecla para continuar");


                            break;

                        case 2:
                            serepiteaguila=false;
                            break;
                        default:
                            cout << "opcion equivocada" << endl;
                            Sleep(1500);
                            serepiteaguila=true;
                            break;
                        }

                    }
                    while(serepiteaguila==true);

                }

                ///Se llama a la funcion GanarFF para saber si con los dados lanzados y/o modificados se gano la partida.

                ///si  gana con escalera simple
                if(GanarFF(vJugadores,jugadorActual))
                {

                    FinalizoFF(vJugadores,cero,FinFF,jugadorActual);

                    rlutil::locate(30,25);
                    cout << "Ganaste Fase Final con escalera" << endl;
                    Sleep(2000);
                }

                /// si gana con escalera salamandra
                else
                {
                    if(BendSalamandra)
                    {
                        if(GanarFFS(vJugadores,jugadorActual))
                        {


                            FinalizoFF(vJugadores,cero,FinFF,jugadorActual);

                            rlutil::locate(30,25);
                            cout << "Ganaste la Fase Final con escalera reducida (Salamandra)" << endl;
                            Sleep(2000);

                        }
                    }


                    ///Se verifica si el jugador tiene la bendicion de la medusa.


                    else
                    {

                        /// si gana con escalera medusa
                        if(BendMedusa)
                        {
                            if(GanarFFM(vJugadores,jugadorActual))
                            {

                                FinalizoFF(vJugadores,cero,FinFF,jugadorActual);

                                rlutil::locate(30,25);
                                cout << "Ganaste la Fase Final con dados repetidos (Bendicion de la Medusa)" << endl;
                                Sleep(2000);
                            }

                        }
                    }
                }


            }

        }





//bool cero es para saber si tiene 0 estatuillas, bool finFF pone fin a la fase final.

        void FinalizoFF( jugadores vJugadores[2], bool cero, bool& FinFF,int jugadorActual)
        {
            if(cero==1)
            {
                vJugadores[jugadorActual].PuntosGanMas+=50;
            }
            else
            {
                vJugadores[jugadorActual].PuntosGan+=15;
            }

            FinFF=true;
        }

        /*Mejorar

        void Reiniciar(jugadores vJugadores[2], estatuas estatuillas){
            for(int x=0;x<2;x++){
            vJugadores[x].puntos = 0;
            vJugadores[x].PuntosEst=0;
            vJugadores[x].PuntosEstMas=0;
            vJugadores[x].PuntosEstMenos=0;
            vJugadores[x].PuntosGan=0;
            vJugadores[x].PuntosGanMas=0;
            vJugadores[x].PuntosLanz=0;
            vJugadores[x].PuntosCangrejo=0;
            vJugadores[x].PuntosHormiga=0;

            vJugadores[x].intentoCangrejo=0;
            vJugadores[x].intentoHormiga=0;
            vJugadores[x].intentoMedusa=0;
            vJugadores[x].intentoAguila=0;
            vJugadores[x].intentoSalamandra=0;
            for(int i=0;i<5;i++){
            vJugadores[x].vEstatuillasObtenidas[i]=false;
            }
            }
            for(int p=0;p<5;p++){
            estatuillas.vEstatuillasDisponibles[p]=true;
            }

        }


        */









