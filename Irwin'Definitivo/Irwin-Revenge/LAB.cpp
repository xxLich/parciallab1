#include <iostream>
#include "rlutil.h"
#include "dado.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "mesaydados.h"
#include "LogicaDosJugadores.h"
#include "estructuras.h"

using namespace std;

int EstatuillasCero2(bool vect[5])
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


void LAB1(jugadores vJugadores[2],estatuas estatuillas)
{


    /// variables fase expedicion

    bool tiro1;
    bool tiro2;
    int select=0;
    bool Mcangrejo=false;
    bool Mhormiga=false;
    bool Mmedusa= false;
    bool Maguila=false;
    bool Msalamandra=false;
    int contM1=0, contM2=0;
    int contAguila1=0, contAguila2=0;

    /// variables fase final
    bool finFF=false ,  BH=true , BH2=true , serepiteaguila, serepiteBH;
    bool serepitehorm=false;
    bool serepiteaguila2, serepiteBH2 , serepitehorm2;
    bool gano1=false , gano2=false;
    int Bcangrejo=0 , Bcangrejo2=0;
    int opcionAguila , opcionAguiladado , NumA , NumH , Horm , Hormiga;
    int opcionAguila2 , opcionAguiladado2 , NumA2 , NumH2 , Horm2 , Hormiga2;
    bool cero1=EstatuillasCero(vJugadores[0].bendicion);
    bool cero2=EstatuillasCero(vJugadores[1].bendicion);
    int contF1=0 , contF2=0;
    //







    /// Empieza la Fase de expedicion

    do
    {

        ///Juega jugador 1

        ///Se evalua si esta activa la maldicion de la Medusa



        if(!vJugadores[0].vEstatuillasObtenidas[2] || contM1==3)
        {

            /// Jugador 1 juega una ronda

            do
            {
                dibujarEstatuilla(estatuillas);
                int contAguila2=0;
                rlutil::locate(30,25);
                cout<<"                                                 ";
                rlutil::locate(30,25);
                cout << vJugadores[0].nombre <<" Selecciona una estatuilla";

                rlutil::locate(30,27);
                cout<<"                                              ";
                rlutil::locate(30,27);
                cin >> select;
                switch (select)
                {
                case 1:
                    if(Mcangrejo)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir" << endl;
                        Sleep(1500);
                        tiro1=false;
                    }
                    else
                    {


                        switch (vJugadores[1].vEstatuillasObtenidas[4])
                        {
                        case true:


                            /// tira jugador 1
                            mostrarDatosJugadorUno(vJugadores);





///*****************************

                            /// llena los vectores de dados de los 2 jugadores
                            llenarVectorDados(vJugadores);

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[1];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[2];

                            /// lanzar dados



///******************************


                            if(cangrejo_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                            {
                                vJugadores[0].vEstatuillasObtenidas[0]=true;
                                estatuillas.vEstatuillasDisponibles[0]= false;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);
                                dibujarEstatuilla(estatuillas);

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Jugador "<<vJugadores[1].nombre <<" Tira un dado";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[1].dados[0];
                                vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0];

                                Mcangrejo=true;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Se le descontaron a "<<vJugadores[0].nombre <<"  "<< vJugadores[1].dados[0] << "  puntos" << endl;
                                Sleep(1500);
                                tiro1=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro1=true;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                            }
                            break;

                        case false:

                            /// tira jugador 1
                            mostrarDatosJugadorUno(vJugadores);

                            /// F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[1];



                            /// si jugador 1 gano cangrejo
                            if(cangrejo(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                            {

                                vJugadores[0].vEstatuillasObtenidas[0]=true;
                                estatuillas.vEstatuillasDisponibles[0]=false;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);

                                dibujarEstatuilla(estatuillas);

                                /// tira jugador 2
                                mostrarDatosJugadorDos(vJugadores);

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Jugador "<<vJugadores[1].nombre<< "Tira un dado";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[1].dados[0];
                                vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0];
                                Mcangrejo=true;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Se le descontaron a "<< vJugadores[0].nombre << " " << vJugadores[1].dados[0] << " puntos"<<endl;
                                Sleep(1500);
                                tiro1=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro1=true;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                            }
                            break;
                        }

                    }
                    if(vJugadores[1].vEstatuillasObtenidas[3])
                    {
                        contAguila1++;
                    }

                    break;
                case 2:
                    if(Mhormiga)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                        Sleep(1500);
                        tiro1=false;
                    }
                    else
                    {
                        switch (vJugadores[1].vEstatuillasObtenidas[4])
                        {
                        case true:

                            /// tira jugador 1
                            mostrarDatosJugadorUno(vJugadores);


                            ///F
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[1];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[2];


                            /// si el lanzamiento anterior gana hormiga
                            if(hormiga_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                            {
                                vJugadores[0].vEstatuillasObtenidas[1]=true;
                                estatuillas.vEstatuillasDisponibles[1]=false;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);

                                dibujarEstatuilla(estatuillas);

                                /// tira jugador 2
                                mostrarDatosJugadorDos(vJugadores);

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout <<vJugadores[1].nombre <<" tira 2 dado"<<endl;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Primer dado: ";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[1].dados[0];
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Segundo dado: ";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[1].dados[1];

                                vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0]-vJugadores[1].dados[1];
                                Mhormiga=true;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Se le descontaron a "<<vJugadores[0].nombre << vJugadores[1].dados[0] << " y " << vJugadores[1].dados[1] << " puntos"<<endl;
                                Sleep(1500);

                                tiro1=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro1=true;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                            }
                            break;

                        case false:

                            /// tira jugador 1

                            mostrarDatosJugadorUno(vJugadores);

                            ///F


                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[1];



                            /// si jugador 1 gana hormiga
                            if(hormiga(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                            {

                                vJugadores[0].vEstatuillasObtenidas[1]=true;
                                estatuillas.vEstatuillasDisponibles[1]=false;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);
                                rlutil::locate(30,25);
                                cout<<"                                              ";

                                dibujarEstatuilla(estatuillas);

                                /// tira jugador 2

                                mostrarDatosJugadorDos(vJugadores);

                                ///F

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Jugador "<< vJugadores[1].nombre <<"tira 2 dado"<<endl;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Primer dado: ";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[1].dados[0];
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Segundo dado: ";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[1].dados[1];
                                vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0]-vJugadores[1].dados[1];
                                Mhormiga=true;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Se le descontaron a "<<vJugadores[0].nombre << vJugadores[1].dados[0] << " y " << vJugadores[1].dados[1] << " puntos"<<endl;
                                Sleep(1500);
                                tiro1=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro1=true;
                            }
                            break;
                        }
                    }
                    if(vJugadores[1].vEstatuillasObtenidas[3])
                    {
                        contAguila1++;
                    }

                    break;
                case 3:
                    if(Mmedusa)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                        Sleep(1500);
                        tiro1=false;
                    }
                    else
                    {
                        switch (vJugadores[1].vEstatuillasObtenidas[4])
                        {
                        case true:

                            mostrarDatosJugadorUno(vJugadores);

                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[1];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[2];


                            /// si jugador 1 gana medusa
                            if(medusa_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                            {

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);
                                vJugadores[0].vEstatuillasObtenidas[2] = true;
                                estatuillas.vEstatuillasDisponibles[2] = false;
                                Mmedusa=true;
                                tiro1=true;

                                dibujarEstatuilla(estatuillas);
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro1=true;
                            }
                            break;
                        case false:


                            /// tira jugador 1
                            mostrarDatosJugadorUno(vJugadores);

                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[1];


                            /// si jugador 1 gana medusa
                            if(medusa(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                            {

                                vJugadores[0].vEstatuillasObtenidas[2]=true;
                                estatuillas.vEstatuillasDisponibles[2]=false;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion" <<endl;
                                Sleep(1500);
                                Mmedusa=true;
                                tiro1=true;

                                dibujarEstatuilla(estatuillas);

                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro1=true;
                            }
                            break;
                        }
                    }
                    if(vJugadores[1].vEstatuillasObtenidas[3])
                    {
                        contAguila1++;
                    }
                    break;
                case 4:
                    if(Maguila)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir";
                        Sleep(1500);
                        tiro1=false;
                    }
                    else
                    {
                        switch (vJugadores[1].vEstatuillasObtenidas[4])
                        {
                        case true:

                            /// tira jugador 1
                            mostrarDatosJugadorUno(vJugadores);

                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[1];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[2];


                            /// si jugador 1 gana aguila
                            if(aguila_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                            {

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion";
                                Sleep(1500);
                                vJugadores[0].vEstatuillasObtenidas[3]=true;
                                estatuillas.vEstatuillasDisponibles[3]=false;

                                Maguila=true;
                                tiro1=true;

                                dibujarEstatuilla(estatuillas);
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro1=true;
                            }
                            break;

                        case false:

                            /// tira jugador 1
                            mostrarDatosJugadorUno(vJugadores);

                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[1];


                            /// si jugador 1 gana aguila
                            if(aguila(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                            {

                                vJugadores[0].vEstatuillasObtenidas[3]=true;
                                estatuillas.vEstatuillasDisponibles[3]=false;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion";
                                Sleep(1500);
                                Maguila=true;
                                tiro1=true;

                                dibujarEstatuilla(estatuillas);

                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro1=true;
                            }
                            break;

                        }
                    }
                    if(vJugadores[1].vEstatuillasObtenidas[3])
                    {
                        contAguila1++;
                    }


                    break;
                case 5:
                    if(Msalamandra)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir";
                        Sleep(1500);
                        tiro1=false;
                    }
                    else
                    {


                        /// si el jugador 2 tiene esta estatuilla
                        switch (vJugadores[1].vEstatuillasObtenidas[4])
                        {
                        case true:
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Estatuilla ya ganada, vuelva a elegir";
                            Sleep(1500);
                            tiro1=false;

                            break;


                        case false:

                            /// tira jugador 1
                            mostrarDatosJugadorUno(vJugadores);
                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[0].dados[1];


                            /// si jugador 1 gana salamandra
                            if(salamandra(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                            {

                                vJugadores[0].vEstatuillasObtenidas[4]=true;
                                estatuillas.vEstatuillasDisponibles[4]=false;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion";
                                Sleep(1500);
                                Msalamandra=true;
                                tiro1=true;

                                dibujarEstatuilla(estatuillas);

                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro1=true;
                            }
                            break;
                        }
                    }

                    if(vJugadores[1].vEstatuillasObtenidas[3])
                    {
                        contAguila1++;
                    }

                    break;
                default:
                    rlutil::locate(30,25);
                    cout<<"                                              ";
                    rlutil::locate(30,25);
                    cout << "Eleccion incorrecta, vuelva a elegir";
                    Sleep(1500);
                    tiro1=false;
                    break;
                }

            }



            while(tiro1==false || contAguila1==1);
        }

        /// Jugador 1 esta maldecido por la estampilla medusa, pierde una ronda

        else
        {
            contM1++;
        }

        /// Juega jugador 2

        ///Se evalua si esta activa la maldicion de la Medusa

        if(!vJugadores[1].vEstatuillasObtenidas[2] || contM2==3)
        {

            // Jugador 2 juega una ronda

            do
            {
                dibujarEstatuilla(estatuillas);
                int contAguila1=0;
                rlutil::locate(30,25);
                cout<<"                                                 ";
                rlutil::locate(30,25);
                cout << vJugadores[1].nombre <<" Selecciona una estatuilla";

                rlutil::locate(30,27);
                cout<<"                                              ";
                rlutil::locate(30,27);
                cin >> select;
                switch (select)
                {
                case 1:
                    if(Mcangrejo)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir" << endl;
                        Sleep(1500);
                        tiro2=false;

                    }
                    else
                    {
                        switch (vJugadores[0].vEstatuillasObtenidas[4])
                        {
                        case true:

                            mostrarDatosJugadorDos(vJugadores);

                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[1];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[2];


                            /// si jugador 2 gana cangrejo
                            if(cangrejo_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                            {
                                vJugadores[1].vEstatuillasObtenidas[0]=true;
                                estatuillas.vEstatuillasDisponibles[0]=false;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion";
                                Sleep(1500);
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << vJugadores[0].nombre<<" Tira un dado";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[0].dados[0];
                                vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0];
                                Mcangrejo=true;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Se le descontaron a jugador 1 " << vJugadores[0].dados[0] << " puntos";
                                Sleep(1500);
                                tiro2=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro2=true;
                            }
                            break;
                        case false:
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[1];

                            if(cangrejo(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                            {

                                vJugadores[1].vEstatuillasObtenidas[0]=true;
                                estatuillas.vEstatuillasDisponibles[0]=false;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);

                                dibujarEstatuilla(estatuillas);

                                mostrarDatosJugadorUno(vJugadores);

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << vJugadores[0].nombre <<" Tira un dado";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[0].dados[0];
                                vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0];
                                Mcangrejo=true;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Se le descontaron a"<< vJugadores[1].nombre << vJugadores[0].dados[0] << " puntos"<<endl;
                                Sleep(1500);
                                tiro2=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro2=true;
                            }
                            break;
                        }
                    }
                    if(vJugadores[0].vEstatuillasObtenidas[3])
                    {
                        contAguila2++;
                    }
                    break;
                case 2:
                    if(Mhormiga)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                        Sleep(1500);
                        tiro2=false;
                    }
                    else
                    {
                        switch (vJugadores[0].vEstatuillasObtenidas[4])
                        {
                        case true:

                            /// tira jugador 2
                            mostrarDatosJugadorDos(vJugadores);


                            ///F
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[1];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[2];

                            if(hormiga_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                            {
                                vJugadores[1].vEstatuillasObtenidas[1]=true;
                                estatuillas.vEstatuillasDisponibles[1]=false;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);
                                dibujarEstatuilla(estatuillas);
///***********

                                /// F

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Jugador 1 tira 2 dado";
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Primer dado: ";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[0].dados[0];
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Segundo dado: ";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[0].dados[1];

                                vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0]-vJugadores[0].dados[1];
                                Mhormiga=true;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Se le descontaron a jugador 2 " << vJugadores[0].dados[0] << " y " << vJugadores[0].dados[1] << " puntos"<<endl;
                                Sleep(1500);
                                tiro2=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro2=true;
                            }
                            break;
                        case false:


                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[1];

                            if(hormiga(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                            {

                                vJugadores[1].vEstatuillasObtenidas[1]=true;
                                estatuillas.vEstatuillasDisponibles[1]=false;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);

                                dibujarEstatuilla(estatuillas);


                                ///F

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Jugador 2 tira 2 dado";
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Primer dado: ";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[0].dados[0];
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Segundo dado: ";
                                rlutil::locate(30,27);
                                cout<<"                                              ";
                                rlutil::locate(30,27);
                                cin >> vJugadores[0].dados[1];


                                vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0]-vJugadores[0].dados[1];
                                Mhormiga=true;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Se le descontaron a "<<vJugadores[1].nombre << vJugadores[0].dados[0] << " y " << vJugadores[0].dados[1] << " puntos"<<endl;
                                Sleep(1500);
                                tiro2=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro2=true;
                            }
                            break;
                        }
                    }
                    if(vJugadores[0].vEstatuillasObtenidas[3])
                    {
                        contAguila2++;
                    }

                    break;
                case 3:
                    if(Mmedusa)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                        Sleep(1500);
                        tiro2=false;
                    }
                    else
                    {
                        switch (vJugadores[0].vEstatuillasObtenidas[4])
                        {
                        case true:

                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[1];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[2];

                            if(medusa_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                            {

                                vJugadores[1].vEstatuillasObtenidas[2]=true;
                                estatuillas.vEstatuillasDisponibles[2]=false;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);
                                Mmedusa=true;
                                tiro2=true;

                                dibujarEstatuilla(estatuillas);
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro2=true;
                                tiro2=true;
                            }
                            break;
                        case false:


                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[1];

                            if(medusa(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                            {

                                vJugadores[1].vEstatuillasObtenidas[2]=true;
                                estatuillas.vEstatuillasDisponibles[2]=false;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);
                                Mmedusa=true;
                                tiro2=true;

                                dibujarEstatuilla(estatuillas);

                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro2=true;

                            }
                            break;
                        }
                    }

                    if(vJugadores[0].vEstatuillasObtenidas[3])
                    {
                        contAguila2++;
                    }
                    break;
                case 4:
                    if(Maguila)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                        Sleep(1500);
                        tiro2=false;
                    }
                    else
                    {
                        switch (vJugadores[0].vEstatuillasObtenidas[4])
                        {
                        case true:


                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[1];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[2];

                            if(aguila_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                            {

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);
                                vJugadores[1].vEstatuillasObtenidas[3]=true;
                                estatuillas.vEstatuillasDisponibles[3]=false;
                                Maguila=true;
                                tiro2=true;

                                dibujarEstatuilla(estatuillas);
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro2=true;
                            }
                            break;

                        case false:

                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[1];

                            if(aguila(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                            {

                                vJugadores[1].vEstatuillasObtenidas[3]=true;
                                estatuillas.vEstatuillasDisponibles[3]=false;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);
                                Maguila=true;
                                tiro2=true;

                                dibujarEstatuilla(estatuillas);

                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro2=true;

                            }
                            break;
                        }

                    }
                    if(vJugadores[0].vEstatuillasObtenidas[3])
                    {
                        contAguila2++;
                    }

                    break;
                case 5:
                    if(Msalamandra)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                        Sleep(1500);
                        tiro2=false;
                        break;
                    }
                    else
                    {
                        switch (vJugadores[0].vEstatuillasObtenidas[4])
                        {
                        case true:
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                            Sleep(1500);
                            tiro2=false;

                            break;

                        case false:

                            mostrarDatosJugadorDos(vJugadores);

                            ///F

                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[0];
                            rlutil::locate(30,25);
                            cout<<"                                              ";
                            rlutil::locate(30,25);
                            cout << "Tire dado: ";
                            rlutil::locate(30,27);
                            cout<<"                                              ";
                            rlutil::locate(30,27);
                            cin >> vJugadores[1].dados[1];

                            if(salamandra(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                            {

                                vJugadores[1].vEstatuillasObtenidas[4]=true;
                                estatuillas.vEstatuillasDisponibles[4]=false;
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                Sleep(1500);
                                Msalamandra=true;
                                tiro2=true;

                                dibujarEstatuilla(estatuillas);

                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                Sleep(1500);
                                tiro2=true;

                                break;
                            }
                        }

                    }
                    if(vJugadores[0].vEstatuillasObtenidas[3])
                    {
                        contAguila2++;
                    }

                    break;

                default:
                    rlutil::locate(30,25);
                    cout<<"                                              ";
                    rlutil::locate(30,25);
                    cout << "Eleccion incorrecta, vuelva a elegir"<<endl;
                    Sleep(1500);
                    tiro2=false;
                    break;


                }
            }
            while(tiro2==false || contAguila2==1);
        }

        // Jugador 2 esta maldecido por la estampilla medusa, pierde una ronda

        else
        {
            contM2++;

        }

    }
    while(TodasSonVerdaderas(vJugadores)!= true);






    /// termina fase expedicion , comienza fase final

///*******************************************************************************************

do{

        //Ronda para el primer jugador

        do{

            //BH es un booleano que usare para anotar por solo una vez un numero y usarlo por si tiene activo la bendicion de la hormiga (leer bendicion).

            if(BH && vJugadores[0].bendicion[1]){
                do{
                    rlutil::locate(30,25);
                    cout << "Elige un numero del 1 al 6: ";
                    cin >> NumH;
                    rlutil::locate(30, 25);
                    cout << "                                                                      ";

                    if(NumH>0 && NumH<7){
                        BH=true;
                        serepiteBH=false;
                    }
                    else{
                        rlutil::locate(30,26);
                        cout << "Numero incorrecto";
                        serepiteBH=true;
                    }

                }while(serepiteBH==true);
                rlutil::locate(30, 26);
                    cout << "                                                                      ";
            }

            //contF1 marca las rondas jugadas, sirve para los puntos y para indicar si se gano la Fase Final en la primera ronda.

            contF1++;
            vJugadores[0].PuntosLanz=vJugadores[0].PuntosLanz-contF1;

            //Tiro de los dados

            rlutil::locate(30,25);
            cout << "Jugador " << vJugadores[0].nombre << endl;

            //Locate 30 26 van el valor de dados manualmente, para el 2 jugadores hay que sacar eso y poner la funcion de dadosmesa y el valor guardarlo
            //en su vector correspondiente (vJugador(x).dados(x).

            rlutil::locate(30,26);
            cout << "Dado 1: ";
            cin >> vJugadores[0].dados[0];
            rlutil::locate(30, 26);
            cout << "                                                                      ";
            rlutil::locate(30,26);
            cout << "Dado 2: ";
            cin >> vJugadores[0].dados[1];
            rlutil::locate(30, 26);
            cout << "                                                                      ";
            rlutil::locate(30,26);
            cout << "Dado 3: ";
            cin >> vJugadores[0].dados[2];
            rlutil::locate(30, 26);
            cout << "                                                                      ";
            rlutil::locate(30,26);
            cout << "Dado 4: ";
            cin >> vJugadores[0].dados[3];
            rlutil::locate(30, 26);
            cout << "                                                                      ";
            rlutil::locate(30,26);
            cout << "Dado 5: ";
            cin >> vJugadores[0].dados[4];
            rlutil::locate(30, 25);
            cout << "                                                                      ";
            rlutil::locate(30, 26);
            cout << "                                                                      ";

            //Preguntamos si el jugador tiene la bendicion hormiga.

            if(vJugadores[0].bendicion[1]){
                rlutil::locate(30,25);
                cout << "Desea cambiar el valor de algun dado por el numero: " << NumH << endl;
                rlutil::locate(30,26);
                cout << "     1     - Si" << endl;
                rlutil::locate(30,27);
                cout << "     2     - No" << endl;

                // Usamos un do while interno que nos servira por si el jugador escoje mal un numero asi tiene la oportunidad de elegir bien.

                do{

                    // Horm = Eleccion 1 o 2.
                    // Hormiga = Eleccion de dado para cambiar valor (por BH)
                    rlutil::locate(30,28);
                    cin >> Horm;
                    rlutil::locate(30, 25);
                    cout << "                                                                      ";
                    rlutil::locate(30, 26);
                    cout << "                                                                      ";
                    rlutil::locate(30, 27);
                    cout << "                                                                      ";
                    rlutil::locate(30, 28);
                    cout << "                                                                      ";
                    switch (Horm) {
                        case 1:
                            rlutil::locate(30, 25);
                            cout << "Que dado desea cambiar (1 al 5)" << endl;
                            rlutil::locate(30, 26);
                            cout << "Dado 1: " << vJugadores[0].dados[0] << "    Dado 2: " << vJugadores[0].dados[1] << "    Dado 3: " << vJugadores[0].dados[2]<< endl;
                            rlutil::locate(30, 27);
                            cout << "    Dado 4: " << vJugadores[0].dados[3]<< "    Dado 5: " << vJugadores[0].dados[4]<< endl;
                                rlutil::locate(30,28);
                                cin >> Hormiga;
                                rlutil::locate(30, 25);
                                cout << "                                                                      ";
                                rlutil::locate(30, 26);
                                cout << "                                                                      ";
                                rlutil::locate(30, 27);
                                cout << "                                                                      ";
                                rlutil::locate(30, 28);
                                cout << "                                                                      ";

                                switch (Hormiga) {
                                    case 1:

                                        vJugadores[0].dados[0]=NumH;
                                        serepitehorm=false;

                                        //serepitehorm si es falso saldra del do whilee interno.

                                        break;
                                    case 2:

                                        vJugadores[0].dados[1]=NumH;
                                        serepitehorm=false;
                                        break;
                                    case 3:

                                        vJugadores[0].dados[2]=NumH;
                                        serepitehorm=false;
                                        break;
                                    case 4:

                                        vJugadores[0].dados[3]=NumH;
                                        serepitehorm=false;
                                        break;
                                    case 5:

                                        vJugadores[0].dados[4]=NumH;
                                        serepitehorm=false;
                                        break;

                                    default:
                                        rlutil::locate(35, 28);
                                        cout << "(opcion equivocada, elegi nuevamente)" << endl;

                                        rlutil::locate(30,25);
                                        cout << "Desea cambiar el valor de algun dado por el numero: " << NumH << endl;
                                        rlutil::locate(30,26);
                                        cout << "     1     - Si" << endl;
                                        rlutil::locate(30,27);
                                        cout << "     2     - No" << endl;

                                        serepitehorm=true;

                                        //serepitehorm es true, por lo tanto cumple con el requisito del do while, entonces se repite vuelta, esto es porque eligio mal una opcion.

                                        break;
                                }
                            break;

                        case 2:

                            serepitehorm=false;
                            break;
                        default:
                            rlutil::locate(35, 28);
                            cout << "(opcion equivocada, elegi nuevamente)" << endl;

                            rlutil::locate(30,25);
                            cout << "Desea cambiar el valor de algun dado por el numero: " << NumH << endl;
                            rlutil::locate(30,26);
                            cout << "     1     - Si" << endl;
                            rlutil::locate(30,27);
                            cout << "     2     - No" << endl;

                            serepitehorm=true;
                    }
                    }while(serepitehorm==true);


                }

        //Pregunto por si el jugador tiene la bendicion aguila

            if(vJugadores[0].bendicion[3]){
                rlutil::locate(30,25);
                cout << "Desea cambiar el valor de algun dado?"<< endl;
                rlutil::locate(30,26);
                cout << "     1     - Si" << endl;
                rlutil::locate(30,27);
                cout << "     2     - No" << endl;

                // Usamos un do while interno que nos servira por si el jugador escoje mal un numero asi tiene la oportunidad de elegir bien (NumA = variable para la eleccion).

                do{
                    rlutil::locate(30,28);
                    cin >> NumA;
                    rlutil::locate(30, 25);
                    cout << "                                                                      ";
                    rlutil::locate(30, 26);
                    cout << "                                                                      ";
                    rlutil::locate(30, 27);
                    cout << "                                                                      ";
                    rlutil::locate(30, 28);
                    cout << "                                                                      ";
                    switch (NumA) {
                        case 1:
                            rlutil::locate(30, 25);
                            cout << "Que dado desea cambiar (1 al 5)" << endl;
                            rlutil::locate(30, 26);
                            cout << "Dado 1: " << vJugadores[0].dados[0] << "    Dado 2: " << vJugadores[0].dados[1] << "    Dado 3: " << vJugadores[0].dados[2]<< endl;
                            rlutil::locate(30, 27);
                            cout << "    Dado 4: " << vJugadores[0].dados[3]<< "    Dado 5: " << vJugadores[0].dados[4]<< endl;
                                rlutil::locate(30,28);
                                cin >> opcionAguiladado;
                                rlutil::locate(30, 25);
                                cout << "                                                                      ";
                                rlutil::locate(30, 26);
                                cout << "                                                                      ";
                                rlutil::locate(30, 27);
                                cout << "                                                                      ";
                                rlutil::locate(30, 28);
                                cout << "                                                                      ";

                                switch (opcionAguiladado) {
                                    case 1:

                                        rlutil::locate(30,25);
                                        cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                        rlutil::locate(30,26);
                                        cin >> opcionAguila;
                                        rlutil::locate(30, 25);
                                        cout << "                                                                      ";
                                        rlutil::locate(30, 26);
                                        cout << "                                                                      ";

                                        //Se cambia el valor del dado por un valor de preferencia.

                                        if(opcionAguila>0 && opcionAguila<7){
                                            vJugadores[0].dados[0]=opcionAguila;
                                            serepiteaguila=false;
                                        }
                                        else{
                                            rlutil::locate(30,27);
                                            cout << "opcion equivocada" << endl;

                                            serepiteaguila=true;
                                            //Si elegis mal entonces por medio de serepiteaguila=true vuelve a elegir un dado
                                        }
                                        break;
                                    case 2:
                                        rlutil::locate(30,25);
                                        cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                        rlutil::locate(30,26);
                                        cin >> opcionAguila;
                                        rlutil::locate(30, 25);
                                        cout << "                                                                      ";
                                        rlutil::locate(30, 26);
                                        cout << "                                                                      ";

                                        if(opcionAguila>0 && opcionAguila<7){
                                            vJugadores[0].dados[1]=opcionAguila;
                                            serepiteaguila=false;
                                        }
                                        else{
                                            rlutil::locate(30,27);
                                            cout << "opcion equivocada" << endl;

                                            serepiteaguila=true;
                                        }
                                        break;
                                    case 3:
                                        rlutil::locate(30,25);
                                        cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                        rlutil::locate(30,26);
                                        cin >> opcionAguila;
                                        rlutil::locate(30, 25);
                                        cout << "                                                                      ";
                                        rlutil::locate(30, 26);
                                        cout << "                                                                      ";

                                        if(opcionAguila>0 && opcionAguila<7){
                                            vJugadores[0].dados[2]=opcionAguila;
                                            serepiteaguila=false;
                                        }
                                        else{
                                            rlutil::locate(30,27);
                                            cout << "opcion equivocada" << endl;

                                            serepiteaguila=true;
                                        }
                                        break;
                                    case 4:
                                        rlutil::locate(30,25);
                                        cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                        rlutil::locate(30,26);
                                        cin >> opcionAguila;
                                        rlutil::locate(30, 25);
                                        cout << "                                                                      ";
                                        rlutil::locate(30, 26);
                                        cout << "                                                                      ";

                                        if(opcionAguila>0 && opcionAguila<7){
                                            vJugadores[0].dados[3]=opcionAguila;
                                            serepiteaguila=false;
                                        }
                                        else{
                                            rlutil::locate(30,27);
                                            cout << "opcion equivocada" << endl;

                                            serepiteaguila=true;
                                        }
                                        break;
                                    case 5:
                                        rlutil::locate(30,25);
                                        cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                        rlutil::locate(30,26);
                                        cin >> opcionAguila;
                                        rlutil::locate(30, 25);
                                        cout << "                                                                      ";
                                        rlutil::locate(30, 26);
                                        cout << "                                                                      ";

                                        if(opcionAguila>0 && opcionAguila<7){
                                            vJugadores[0].dados[4]=opcionAguila;
                                            serepiteaguila=false;
                                        }
                                        else{
                                            rlutil::locate(30,27);
                                            cout << "opcion equivocada" << endl;

                                            serepiteaguila=true;
                                        }
                                        break;

                                    default:
                                        cout << "opcion equivocada" << endl;
                                        serepiteaguila=true;
                                        break;
                                }
                            break;

                            case 2:
                                serepiteaguila=false;
                                break;
                            }

                        }while(serepiteaguila==true);

                    }

            //Se llama a la funcion GanarFF para saber si con los dados lanzados y/o modificados se gano la partida.

                if(GanarFF(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2], vJugadores[0].dados[3], vJugadores[0].dados[4])){
                    FinalizoFF(gano1, cero1, vJugadores[0].PuntosGan , vJugadores[0].PuntosGanMas, finFF);
                    rlutil::locate(30,25);
                    cout << "Ganaste Fase Final con escalera" << endl;
                    break;
                }
                else{

                    //Se verifica si el jugador tiene la bendicion del cangrejo.

                    if(vJugadores[0].bendicion[0]){
                        if(contF1==1){
                            Bcangrejo++;

                            //Bcangrejo es un contador que cuando llega a 1, se repite el do while por solo una vez y asi cumpliendo con la bendicion cangrejo.

                        }
                    }

                    //Se verifica si el jugador tiene la bendicion de la salamandra.

                    if(vJugadores[0].bendicion[4]){
                        if(GanarFFS(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2], vJugadores[0].dados[3], vJugadores[0].dados[4])){
                            FinalizoFF(gano1, cero1, vJugadores[0].PuntosGan, vJugadores[0].PuntosGanMas, finFF);
                            rlutil::locate(30,25);
                            cout << "Ganaste la Fase Final con escalera reducida (Salamandra)" << endl;
                            break;
                        }
                    }

                    //Se verifica si el jugador tiene la bendicion de la medusa.

                    if(vJugadores[0].bendicion[2]){
                        if(GanarFFM(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2], vJugadores[0].dados[3], vJugadores[0].dados[4])){
                            FinalizoFF(gano1, cero1, vJugadores[0].PuntosGan, vJugadores[0].PuntosGanMas, finFF);
                            rlutil::locate(30,25);
                            cout << "Ganaste la Fase Final con dados repetidos (Bendicion de la Medusa)" << endl;
                            break;
                        }
                    }
                }

            //La condicion del while es por si se repite una ronda (La unica que se repite es la primera ronda por tiene la bendicion del cangrejo) o por si finalizo la fase (Ganaria jugador 1)

            }while(Bcangrejo==1 && finFF==false);

        //Antes de empezar el otro do while(ronda del segundo jugador) se verifica si el jugador 1 gano la partida.

            if(finFF==false){

                //Basicamente se hace lo mismo que hicimos con el jugador 1.

                do{

            //BH es un booleano que usare para anotar por solo una vez un numero y usarlo por si tiene activo la bendicion de la hormiga (leer bendicion).

            if(BH && vJugadores[1].bendicion[1]){
                do{
                    rlutil::locate(30,25);
                    cout << "Elige un numero del 1 al 6: ";
                    cin >> NumH2;
                    rlutil::locate(30, 25);
                    cout << "                                                                      ";

                    if(NumH2>0 && NumH2<7){
                        BH2=true;
                        serepiteBH2=false;
                    }
                    else{
                        rlutil::locate(30,26);
                        cout << "Numero incorrecto";
                        serepiteBH2=true;
                    }

                }while(serepiteBH2==true);
                rlutil::locate(30, 26);
                    cout << "                                                                      ";
            }

             //contF2 rondas

            contF2++;
            vJugadores[1].PuntosLanz=vJugadores[1].PuntosLanz-contF2;


            //Tiro de los dados

            rlutil::locate(30,25);
            cout << "Jugador " << vJugadores[1].nombre << endl;

            //Locate 30 26 van el valor de dados manualmente, para el 2 jugadores hay que sacar eso y poner la funcion de dadosmesa y el valor guardarlo
            //en su vector correspondiente (vJugador(x).dados(x).

            rlutil::locate(30,26);
            cout << "Dado 1: ";
            cin >> vJugadores[1].dados[0];
            rlutil::locate(30, 26);
            cout << "                                                                      ";
            rlutil::locate(30,26);
            cout << "Dado 2: ";
            cin >> vJugadores[1].dados[1];
            rlutil::locate(30, 26);
            cout << "                                                                      ";
            rlutil::locate(30,26);
            cout << "Dado 3: ";
            cin >> vJugadores[1].dados[2];
            rlutil::locate(30, 26);
            cout << "                                                                      ";
            rlutil::locate(30,26);
            cout << "Dado 4: ";
            cin >> vJugadores[1].dados[3];
            rlutil::locate(30, 26);
            cout << "                                                                      ";
            rlutil::locate(30,26);
            cout << "Dado 5: ";
            cin >> vJugadores[1].dados[4];
            rlutil::locate(30, 25);
            cout << "                                                                      ";
            rlutil::locate(30, 26);
            cout << "                                                                      ";

            //Preguntamos si el jugador tiene la bendicion hormiga.

            if(vJugadores[1].bendicion[1]){
                rlutil::locate(30,25);
                cout << "Desea cambiar el valor de algun dado por el numero: " << NumH2 << endl;
                rlutil::locate(30,26);
                cout << "     1     - Si" << endl;
                rlutil::locate(30,27);
                cout << "     2     - No" << endl;

                // Usamos un do while interno que nos servira por si el jugador escoje mal un numero asi tiene la oportunidad de elegir bien.

                do{

                    // Horm = Eleccion 1 o 2.
                    // Hormiga = Eleccion de dado para cambiar valor (por BH)
                    rlutil::locate(30,28);
                    cin >> Horm2;
                    rlutil::locate(30, 25);
                    cout << "                                                                      ";
                    rlutil::locate(30, 26);
                    cout << "                                                                      ";
                    rlutil::locate(30, 27);
                    cout << "                                                                      ";
                    rlutil::locate(30, 28);
                    cout << "                                                                      ";
                    switch (Horm2) {
                        case 1:
                            rlutil::locate(30, 25);
                            cout << "Que dado desea cambiar (1 al 5)" << endl;
                            rlutil::locate(30, 26);
                            cout << "Dado 1: " << vJugadores[1].dados[0] << "    Dado 2: " << vJugadores[1].dados[1] << "    Dado 3: " << vJugadores[1].dados[2]<< endl;
                            rlutil::locate(30, 27);
                            cout << "    Dado 4: " << vJugadores[1].dados[3]<< "    Dado 5: " << vJugadores[1].dados[4]<< endl;
                                rlutil::locate(30,28);
                                cin >> Hormiga2;
                                rlutil::locate(30, 25);
                                cout << "                                                                      ";
                                rlutil::locate(30, 26);
                                cout << "                                                                      ";
                                rlutil::locate(30, 27);
                                cout << "                                                                      ";
                                rlutil::locate(30, 28);
                                cout << "                                                                      ";

                                switch (Hormiga2) {
                                    case 1:

                                        vJugadores[1].dados[0]=NumH2;
                                        serepitehorm2=false;

                                        //serepitehorm si es falso saldra del do whilee interno.

                                        break;
                                    case 2:

                                        vJugadores[1].dados[1]=NumH2;
                                        serepitehorm2=false;
                                        break;
                                    case 3:

                                        vJugadores[1].dados[2]=NumH2;
                                        serepitehorm2=false;
                                        break;
                                    case 4:

                                        vJugadores[1].dados[3]=NumH2;
                                        serepitehorm2=false;
                                        break;
                                    case 5:

                                        vJugadores[1].dados[4]=NumH2;
                                        serepitehorm2=false;
                                        break;

                                    default:
                                        rlutil::locate(35, 28);
                                        cout << "(opcion equivocada, elegi nuevamente)" << endl;

                                        rlutil::locate(30,25);
                                        cout << "Desea cambiar el valor de algun dado por el numero: " << NumH2 << endl;
                                        rlutil::locate(30,26);
                                        cout << "     1     - Si" << endl;
                                        rlutil::locate(30,27);
                                        cout << "     2     - No" << endl;

                                        serepitehorm2=true;

                                        //serepitehorm es true, por lo tanto cumple con el requisito del do while, entonces se repite vuelta, esto es porque eligio mal una opcion.

                                        break;
                                }
                            break;

                        case 2:

                            serepitehorm2=false;
                            break;
                        default:
                            rlutil::locate(35, 28);
                            cout << "(opcion equivocada, elegi nuevamente)" << endl;

                            rlutil::locate(30,25);
                            cout << "Desea cambiar el valor de algun dado por el numero: " << NumH2 << endl;
                            rlutil::locate(30,26);
                            cout << "     1     - Si" << endl;
                            rlutil::locate(30,27);
                            cout << "     2     - No" << endl;

                            serepitehorm2=true;
                    }
                    }while(serepitehorm2==true);


                }

        //Pregunto por si el jugador tiene la bendicion aguila

            if(vJugadores[1].bendicion[3]){
                rlutil::locate(30,25);
                cout << "Desea cambiar el valor de algun dado?"<< endl;
                rlutil::locate(30,26);
                cout << "     1     - Si" << endl;
                rlutil::locate(30,27);
                cout << "     2     - No" << endl;

                // Usamos un do while interno que nos servira por si el jugador escoje mal un numero asi tiene la oportunidad de elegir bien (NumA = variable para la eleccion).

                do{
                    rlutil::locate(30,28);
                    cin >> NumA2;
                    rlutil::locate(30, 25);
                    cout << "                                                                      ";
                    rlutil::locate(30, 26);
                    cout << "                                                                      ";
                    rlutil::locate(30, 27);
                    cout << "                                                                      ";
                    rlutil::locate(30, 28);
                    cout << "                                                                      ";
                    switch (NumA2) {
                        case 1:
                            rlutil::locate(30, 25);
                            cout << "Que dado desea cambiar (1 al 5)" << endl;
                            rlutil::locate(30, 26);
                            cout << "Dado 1: " << vJugadores[1].dados[0] << "    Dado 2: " << vJugadores[1].dados[1] << "    Dado 3: " << vJugadores[1].dados[2]<< endl;
                            rlutil::locate(30, 27);
                            cout << "    Dado 4: " << vJugadores[1].dados[3]<< "    Dado 5: " << vJugadores[1].dados[4]<< endl;
                                rlutil::locate(30,28);
                                cin >> opcionAguiladado2;
                                rlutil::locate(30, 25);
                                cout << "                                                                      ";
                                rlutil::locate(30, 26);
                                cout << "                                                                      ";
                                rlutil::locate(30, 27);
                                cout << "                                                                      ";
                                rlutil::locate(30, 28);
                                cout << "                                                                      ";

                                switch (opcionAguiladado2) {
                                    case 1:

                                        rlutil::locate(30,25);
                                        cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                        rlutil::locate(30,26);
                                        cin >> opcionAguila2;
                                        rlutil::locate(30, 25);
                                        cout << "                                                                      ";
                                        rlutil::locate(30, 26);
                                        cout << "                                                                      ";

                                        //Se cambia el valor del dado por un valor de preferencia.

                                        if(opcionAguila2>0 && opcionAguila2<7){
                                            vJugadores[1].dados[0]=opcionAguila2;
                                            serepiteaguila2=false;
                                        }
                                        else{
                                            rlutil::locate(30,27);
                                            cout << "opcion equivocada" << endl;

                                            serepiteaguila2=true;
                                            //Si elegis mal entonces por medio de serepiteaguila=true vuelve a elegir un dado
                                        }
                                        break;
                                    case 2:
                                        rlutil::locate(30,25);
                                        cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                        rlutil::locate(30,26);
                                        cin >> opcionAguila2;
                                        rlutil::locate(30, 25);
                                        cout << "                                                                      ";
                                        rlutil::locate(30, 26);
                                        cout << "                                                                      ";

                                        if(opcionAguila2>0 && opcionAguila2<7){
                                            vJugadores[1].dados[1]=opcionAguila2;
                                            serepiteaguila2=false;
                                        }
                                        else{
                                            rlutil::locate(30,27);
                                            cout << "opcion equivocada" << endl;

                                            serepiteaguila2=true;
                                        }
                                        break;
                                    case 3:
                                        rlutil::locate(30,25);
                                        cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                        rlutil::locate(30,26);
                                        cin >> opcionAguila2;
                                        rlutil::locate(30, 25);
                                        cout << "                                                                      ";
                                        rlutil::locate(30, 26);
                                        cout << "                                                                      ";

                                        if(opcionAguila2>0 && opcionAguila2<7){
                                            vJugadores[1].dados[2]=opcionAguila2;
                                            serepiteaguila2=false;
                                        }
                                        else{
                                            rlutil::locate(30,27);
                                            cout << "opcion equivocada" << endl;

                                            serepiteaguila2=true;
                                        }
                                        break;
                                    case 4:
                                        rlutil::locate(30,25);
                                        cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                        rlutil::locate(30,26);
                                        cin >> opcionAguila2;
                                        rlutil::locate(30, 25);
                                        cout << "                                                                      ";
                                        rlutil::locate(30, 26);
                                        cout << "                                                                      ";

                                        if(opcionAguila2>0 && opcionAguila2<7){
                                            vJugadores[1].dados[3]=opcionAguila2;
                                            serepiteaguila2=false;
                                        }
                                        else{
                                            rlutil::locate(30,27);
                                            cout << "opcion equivocada" << endl;

                                            serepiteaguila2=true;
                                        }
                                        break;
                                    case 5:
                                        rlutil::locate(30,25);
                                        cout << "Ingrese el valor por el que desea cambiarlo (1 al 6): ";
                                        rlutil::locate(30,26);
                                        cin >> opcionAguila2;
                                        rlutil::locate(30, 25);
                                        cout << "                                                                      ";
                                        rlutil::locate(30, 26);
                                        cout << "                                                                      ";

                                        if(opcionAguila2>0 && opcionAguila2<7){
                                            vJugadores[1].dados[4]=opcionAguila2;
                                            serepiteaguila2=false;
                                        }
                                        else{
                                            rlutil::locate(30,27);
                                            cout << "opcion equivocada" << endl;

                                            serepiteaguila2=true;
                                        }
                                        break;

                                    default:
                                        cout << "opcion equivocada" << endl;
                                        serepiteaguila2=true;
                                        break;
                                }
                            break;

                            case 2:
                                serepiteaguila2=false;
                                break;
                            }

                        }while(serepiteaguila2==true);

                    }

            //Se llama a la funcion GanarFF para saber si con los dados lanzados y/o modificados se gano la partida.

                if(GanarFF(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2], vJugadores[1].dados[3], vJugadores[1].dados[4])){
                    FinalizoFF(gano2, cero2, vJugadores[1].PuntosGan, vJugadores[1].PuntosGanMas, finFF);
                    rlutil::locate(30,25);
                    cout << "Ganaste Fase Final con escalera" << endl;
                    break;
                }
                else{

                    //Se verifica si el jugador tiene la bendicion del cangrejo.

                    if(vJugadores[1].bendicion[0]){
                        if(contF2==1){
                            Bcangrejo2++;

                            //Bcangrejo es un contador que cuando llega a 1, se repite el do while por solo una vez y asi cumpliendo con la bendicion cangrejo.

                        }
                    }

                    //Se verifica si el jugador tiene la bendicion de la salamandra.

                    if(vJugadores[1].bendicion[4]){
                        if(GanarFFS(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2], vJugadores[1].dados[3], vJugadores[1].dados[4])){
                            FinalizoFF(gano2, cero2, vJugadores[1].PuntosGan, vJugadores[1].PuntosGanMas, finFF);
                            rlutil::locate(30,25);
                            cout << "Ganaste la Fase Final con escalera reducida (Bendicion de la Salamandra)" << endl;
                            break;
                        }
                    }

                    //Se verifica si el jugador tiene la bendicion de la medusa.

                    if(vJugadores[1].bendicion[2]){
                        if(GanarFFM(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2], vJugadores[1].dados[3], vJugadores[1].dados[4])){
                            FinalizoFF(gano2, cero2, vJugadores[1].PuntosGan, vJugadores[1].PuntosGanMas, finFF);
                            rlutil::locate(30,25);
                            cout << "Ganaste la Fase Final con dados repetidos (Bendicion de la Medusa)" << endl;
                            break;
                        }
                    }
                }

            //La condicion del while es por si se repite una ronda (La unica que se repite es la primera ronda por tiene la bendicion del cangrejo) o por si finalizo la fase (Ganaria jugador 1)

                }while(Bcangrejo2==1);
            }

    }while(finFF==false || gano1==false || gano2==false);

}






    ///*********************************************************************















///**********************************************************
/// Final Expedicion

