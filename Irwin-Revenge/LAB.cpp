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


    vJugadores[0].bendicion[1]=true;

    bool finFF=false,  BH=true, BH2=true, serepiteaguila, serepiteBH;
    bool serepitehorm=false;
    bool serepiteaguila2, serepiteBH2, serepitehorm2;
    bool gano1=false, gano2=false;
    int Bcangrejo=0, Bcangrejo2=0;
    int opcionAguila, opcionAguiladado, NumA, NumH, Horm, Hormiga;
    int opcionAguila2, opcionAguiladado2, NumA2, NumH2, Horm2, Hormiga2;
    bool cero1=EstatuillasCero2(vJugadores[0].bendicion);
    bool cero2=EstatuillasCero2(vJugadores[1].bendicion);
    int contF1=0, contF2=0;




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
                cout<<"                                              ";
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
                                cout << "Se le descontaron a "<<vJugadores[0].nombre <<" "<< vJugadores[1].dados[0] << " puntos" << endl;
                                tiro1=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
                                tiro1=true;
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
                                cout << "Se le descontaron a "<< vJugadores[0].nombre << vJugadores[1].dados[0] << " puntos"<<endl;
                                tiro1=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
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
                case 2:
                    if(Mhormiga)
                    {
                        rlutil::locate(30,25);
                        cout<<"                                              ";
                        rlutil::locate(30,25);
                        cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
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

                                tiro1=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
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



                            /// si jugador 1 gana hormiga
                            if(hormiga(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                            {

                                vJugadores[0].vEstatuillasObtenidas[1]=true;
                                estatuillas.vEstatuillasDisponibles[1]=false;

                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "Estatuilla ganada, se activa tu maldicion"<<endl;

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
                                tiro1=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
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
                contAguila1=0;
                /// elige estatuilla jugador 2
                mostrarDatosJugadorDos(vJugadores);

                dibujarEstatuilla(estatuillas);

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
                                tiro2=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
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
                                tiro2=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
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
                                tiro2=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
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
                                tiro2=true;
                            }
                            else
                            {
                                rlutil::locate(30,25);
                                cout<<"                                              ";
                                rlutil::locate(30,25);
                                cout << "No ganaste la estatuilla" << endl;
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








    ///*********************************************************************

}













///**********************************************************
/// Final Expedicion


