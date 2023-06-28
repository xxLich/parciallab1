#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "mesa.h"
#include "mesaydados.h"
#include "Logica-dos-jugadores.h"

using namespace std;


struct estatuas
{

    string vEstatuillas[5] = {"1.cangrejo","2.hormiga","3.medusa","4.aguila","5.salamandra"};
    bool vEstatuillasDisponibles[5] =
    {

        true, ///0 cangrejo
        true, ///1 hormiga
        true, ///2 medusa
        true, ///3 aguila
        true  ///4 salamandra
    };


};

struct jugadores
{

    string nombre;
    string vEstatuillas[5] = {"|cangrejo|","|hormiga|","|medusa|","|aguila|","|salamandra|"};
    bool vEstatuillasObtenidas[5] =
    {

        false, ///0 cangrejo
        false, ///1 hormiga
        false, ///2 medusa
        false, ///3 aguila
        false  ///4 salamandra
    };

    int dados[3];
    int puntos = 0;

    bool bendicionCangrejo = false;
    bool bendicionHormiga = false;
    bool bendicionMedusa = false;
    bool bendicionAguila = false;
    bool bendicionSalamandra = false;



};


void seleccionarEstatuilla(int, jugadores[], estatuas);

void datosEnJuego(jugadores[]);

void jugarPorTurno(jugadores[]);

void dibujarEstatuilla(estatuas);

void pedirDatos(jugadores []);

int terminarExpedicion(estatuas);

void cambiarTurnos(jugadores []);

void LAB1 ();


bool TodasSonVerdaderas(jugadores vJugadores[2])
{

    int estJugUno = 0;
    int estJugDos = 0;
    int evaluacion=0;

    for(int i=0; i<5; i++)
    {

        if(vJugadores[0].vEstatuillasObtenidas[i] == true)
        {
            estJugUno++;
        }
    }
    for(int i=0; i<5; i++)
    {
        if(vJugadores[1].vEstatuillasObtenidas[i] == true)
        {

            estJugDos++;
        }
    }
    evaluacion=estJugUno+estJugDos;

    if(evaluacion==5)
    {
        return true;
    }
    return false;
}


















void dosJugadores()
{

    /// booleanos fase expedicion




    bool tiro1 = 1;
    bool tiro2 = 1;

    int select;
    bool Mcangrejo=false;
    bool Mhormiga=false;
    bool Mmedusa= false;
    bool Maguila=false;
    bool Msalamandra=false;
    int contM1=0, contM2=0;
    int contAguila1=0, contAguila2=0;





    bool fin = false;

    /// variables de struct

    jugadores vJugadores[2];
    estatuas estatuillas;



    /// pide los nombres de los 2 vJugadores


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



        /// Se juega por turnos El ganador sale con su turno en true


        jugarPorTurno(vJugadores);








        ///************************************************************************************


        bool tiro1;
        bool tiro2;
        jugadores vJugadores[2];
        int select=0;
        bool Mcangrejo=false;
        bool Mhormiga=false;
        bool Mmedusa= false;
        bool Maguila=false;
        bool Msalamandra=false;
        int contM1=0, contM2=0;
        int contAguila1=0, contAguila2=0;

        // Empieza la Fase de expedicion

        do
        {

            //Juega jugador 1

            //Se evalua si esta activa la maldicion de la Medusa

            if(!vJugadores[0].vEstatuillasObtenidas[2] || contM1==3)
            {

                // Jugador 1 juega una ronda

                do
                {
                    int contAguila2=0;
                    cout << "Jugador 1 elige una estampilla" << endl;
                    cout << "1 - Cangrejo" << endl;
                    cout << "2 - Hormiga" << endl;
                    cout << "3 - Medusa" << endl;
                    cout << "4 - Aguila" << endl;
                    cout << "5 - Salamandra" << endl;
                    cin >> select;
                    switch (select)
                    {
                    case 1:
                        if(Mcangrejo)
                        {
                            cout << "Estampilla ya ganada, vuelva a elegir" << endl;
                            tiro1=false;
                        }
                        else
                        {
                            switch (vJugadores[1].vEstatuillasObtenidas[4])
                            {
                            case true:
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[1];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[2];

                                if(cangrejo_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                                {
                                    vJugadores[0].vEstatuillasObtenidas[0]=true;
                                    estatuillas.vEstatuillasDisponibles[0]= false;

                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    cout << "Jugador 2 tira un dado";
                                    cin >> vJugadores[1].dados[0];
                                    vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0];
                                    Mcangrejo=true;
                                    cout << "Se le descontaron a jugador 1 " << vJugadores[1].dados[0] << " puntos" << endl;
                                    tiro1=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
                                    tiro1=true;
                                }
                                break;
                            case false:
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[1];

                                if(cangrejo(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                                {

                                    vJugadores[0].vEstatuillasObtenidas[0]=true;
                                    estatuillas.vEstatuillasDisponibles[0]=false;

                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    cout << "Jugador 2 tira un dado";
                                    cin >> vJugadores[1].dados[0];
                                    vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0];
                                    Mcangrejo=true;
                                    cout << "Se le descontaron a jugador 1 " << vJugadores[1].dados[0] << " puntos"<<endl;
                                    tiro1=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
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
                            cout << "Estampilla ya ganada, vuelva a elegir"<<endl;
                            tiro1=false;
                        }
                        else
                        {
                            switch (vJugadores[1].vEstatuillasObtenidas[4])
                            {
                            case true:
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[1];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[2];

                                if(hormiga_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                                {
                                    vJugadores[0].vEstatuillasObtenidas[1]=true;
                                    estatuillas.vEstatuillasDisponibles[1]=false;

                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    cout << "Jugador 2 tira 2 dado"<<endl;
                                    cout << "Primer dado: ";
                                    cin >> vJugadores[1].dados[0];
                                    cout << "Segundo dado: ";
                                    cin >> vJugadores[1].dados[1];
                                    vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0]-vJugadores[1].dados[1];
                                    Mhormiga=true;
                                    cout << "Se le descontaron a jugador 1 " << vJugadores[1].dados[0] << " y " << vJugadores[1].dados[1] << " puntos"<<endl;
                                    tiro1=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
                                    tiro1=true;
                                }
                                break;
                            case false:
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[1];

                                if(hormiga(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                                {

                                    vJugadores[0].vEstatuillasObtenidas[1]=true;
                                    estatuillas.vEstatuillasDisponibles[1]=false;

                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    cout << "Jugador 2 tira 2 dado"<<endl;
                                    cout << "Primer dado: ";
                                    cin >> vJugadores[1].dados[0];
                                    cout << "Segundo dado: ";
                                    cin >> vJugadores[1].dados[1];
                                    vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0]-vJugadores[1].dados[1];
                                    Mhormiga=true;
                                    cout << "Se le descontaron a jugador 1 " << vJugadores[1].dados[0] << " y " << vJugadores[1].dados[1] << " puntos"<<endl;
                                    tiro1=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
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
                            cout << "Estampilla ya ganada, vuelva a elegir"<<endl;
                            tiro1=false;
                        }
                        else
                        {
                            switch (vJugadores[1].vEstatuillasObtenidas[4])
                            {
                            case true:
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[1];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[2];

                                if(medusa_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                                {

                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    vJugadores[0].vEstatuillasObtenidas[2] = true;
                                    estatuillas.vEstatuillasDisponibles[2] = false;
                                    Mmedusa=true;
                                    tiro1=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
                                    tiro1=true;
                                }
                                break;
                            case false:
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[1];

                                if(medusa(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                                {

                                    vJugadores[0].vEstatuillasObtenidas[2]=true;
                                    estatuillas.vEstatuillasDisponibles[2]=false;
                                    cout << "Estampilla ganada, se activa tu maldicion" <<endl;
                                    Mmedusa=true;
                                    tiro1=true;

                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
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
                            cout << "Estampilla ya ganada, vuelva a elegir";
                            tiro1=false;
                        }
                        else
                        {
                            switch (vJugadores[1].vEstatuillasObtenidas[4])
                            {
                            case true:
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[1];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[2];

                                if(aguila_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                                {

                                    cout << "Estampilla ganada, se activa tu maldicion";
                                    vJugadores[0].vEstatuillasObtenidas[3]=true;
                                    estatuillas.vEstatuillasDisponibles[3]=false;

                                    Maguila=true;
                                    tiro1=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
                                    tiro1=true;
                                }
                                break;
                            case false:
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[1];

                                if(aguila(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                                {

                                    vJugadores[0].vEstatuillasObtenidas[3]=true;
                                    estatuillas.vEstatuillasDisponibles[3]=false;
                                    cout << "Estampilla ganada, se activa tu maldicion";
                                    Maguila=true;
                                    tiro1=true;

                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
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
                            cout << "Estampilla ya ganada, vuelva a elegir";
                            tiro1=false;
                        }
                        else
                        {
                            switch (vJugadores[1].vEstatuillasObtenidas[4])
                            {
                            case true:
                                cout << "Estampilla ya ganada, vuelva a elegir";
                                tiro1=false;
                                break;
                            case false:
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[0].dados[1];

                                if(salamandra(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                                {

                                    vJugadores[0].vEstatuillasObtenidas[4]=true;
                                    estatuillas.vEstatuillasDisponibles[4]=false;
                                    cout << "Estampilla ganada, se activa tu maldicion";
                                    Msalamandra=true;
                                    tiro1=true;

                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
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
                        cout << "Eleccion incorrecta, vuelva a elegir";
                        tiro1=false;
                        break;
                    }

                }



                while(tiro1==false || contAguila1==1);
            }

            // Jugador 1 esta maldecido por la estampilla medusa, pierde una ronda

            else
            {
                contM1++;
            }

            // Juega jugador 2

            //Se evalua si esta activa la maldicion de la Medusa

            if(!vJugadores[1].vEstatuillasObtenidas[2] || contM2==3)
            {

                // Jugador 2 juega una ronda

                do
                {
                    contAguila1=0;
                    cout << "Jugador 2 elige una estampilla" << endl;
                    cout << "1 - Cangrejo" << endl;
                    cout << "2 - Hormiga" << endl;
                    cout << "3 - Medusa" << endl;
                    cout << "4 - Aguila" << endl;
                    cout << "5 - Salamandra" << endl;
                    cin >> select;
                    switch (select)
                    {
                    case 1:
                        if(Mcangrejo)
                        {
                            cout << "Estampilla ya ganada, vuelva a elegir" << endl;
                            tiro2=false;

                        }
                        else
                        {
                            switch (vJugadores[0].vEstatuillasObtenidas[4])
                            {
                            case true:
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[1];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[2];

                                if(cangrejo_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                                {
                                    vJugadores[1].vEstatuillasObtenidas[0]=true;
                                    estatuillas.vEstatuillasDisponibles[0]=false;

                                    cout << "Estampilla ganada, se activa tu maldicion";
                                    cout << "Jugador 1 tira un dado";
                                    cin >> vJugadores[0].dados[0];
                                    vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0];
                                    Mcangrejo=true;
                                    cout << "Se le descontaron a jugador 1 " << vJugadores[0].dados[0] << " puntos";
                                    tiro2=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
                                    tiro2=true;
                                }
                                break;
                            case false:
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[1];

                                if(cangrejo(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[0]=true;
                                    estatuillas.vEstatuillasDisponibles[0]=false;

                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    cout << "Jugador 1 tira un dado";
                                    cin >> vJugadores[0].dados[0];
                                    vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0];
                                    Mcangrejo=true;
                                    cout << "Se le descontaron a jugador 1 " << vJugadores[0].dados[0] << " puntos"<<endl;
                                    tiro2=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
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
                            cout << "Estampilla ya ganada, vuelva a elegir"<<endl;
                            tiro2=false;
                        }
                        else
                        {
                            switch (vJugadores[0].vEstatuillasObtenidas[4])
                            {
                            case true:
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[1];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[2];

                                if(hormiga_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                                {
                                    vJugadores[1].vEstatuillasObtenidas[1]=true;
                                    estatuillas.vEstatuillasDisponibles[1]=false;

                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    cout << "Jugador 1 tira 2 dado";
                                    cout << "Primer dado: ";
                                    cin >> vJugadores[0].dados[0];
                                    cout << "Segundo dado: ";
                                    cin >> vJugadores[0].dados[1];
                                    vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0]-vJugadores[0].dados[1];
                                    Mhormiga=true;
                                    cout << "Se le descontaron a jugador 2 " << vJugadores[0].dados[0] << " y " << vJugadores[0].dados[1] << " puntos"<<endl;
                                    tiro2=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
                                    tiro2=true;
                                }
                                break;
                            case false:
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[1];

                                if(hormiga(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[1]=true;
                                    estatuillas.vEstatuillasDisponibles[1]=false;

                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    cout << "Jugador 2 tira 2 dado";
                                    cout << "Primer dado: ";
                                    cin >> vJugadores[0].dados[0];
                                    cout << "Segundo dado: ";
                                    cin >> vJugadores[0].dados[1];
                                    vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0]-vJugadores[0].dados[1];
                                    Mhormiga=true;
                                    cout << "Se le descontaron a jugador 2 " << vJugadores[0].dados[0] << " y " << vJugadores[0].dados[1] << " puntos"<<endl;
                                    tiro2=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
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
                            cout << "Estampilla ya ganada, vuelva a elegir"<<endl;
                            tiro2=false;
                        }
                        else
                        {
                            switch (vJugadores[0].vEstatuillasObtenidas[4])
                            {
                            case true:
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[1];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[2];

                                if(medusa_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[2]=true;
                                    estatuillas.vEstatuillasDisponibles[2]=false;
                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    Mmedusa=true;
                                    tiro2=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
                                    tiro2=true;
                                    tiro2=true;
                                }
                                break;
                            case false:
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[1];

                                if(medusa(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[2]=true;
                                    estatuillas.vEstatuillasDisponibles[2]=false;
                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    Mmedusa=true;
                                    tiro2=true;

                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
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
                            cout << "Estampilla ya ganada, vuelva a elegir"<<endl;
                            tiro2=false;
                        }
                        else
                        {
                            switch (vJugadores[0].vEstatuillasObtenidas[4])
                            {
                            case true:
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[1];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[2];

                                if(aguila_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                                {

                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    vJugadores[1].vEstatuillasObtenidas[3]=true;
                                    estatuillas.vEstatuillasDisponibles[3]=false;
                                    Maguila=true;
                                    tiro2=true;
                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
                                    tiro2=true;
                                }
                                break;
                            case false:
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[1];

                                if(aguila(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[3]=true;
                                    estatuillas.vEstatuillasDisponibles[3]=false;
                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    Maguila=true;
                                    tiro2=true;

                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
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
                            cout << "Estampilla ya ganada, vuelva a elegir"<<endl;
                            tiro2=false;
                            break;
                        }
                        else
                        {
                            switch (vJugadores[0].vEstatuillasObtenidas[4])
                            {
                            case true:
                                cout << "Estampilla ya ganada, vuelva a elegir"<<endl;
                                tiro2=false;
                                break;
                            case false:
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[0];
                                cout << "Tire dado: ";
                                cin >> vJugadores[1].dados[1];

                                if(salamandra(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[4]=true;
                                    estatuillas.vEstatuillasDisponibles[4]=false;
                                    cout << "Estampilla ganada, se activa tu maldicion"<<endl;
                                    Msalamandra=true;
                                    tiro2=true;

                                }
                                else
                                {
                                    cout << "No ganaste la estampilla" << endl;
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








///*******************************************************************************************


    }


}











































///--------------------- Funcion 2 vJugadores SI LAB1 ----------------------------------


void LAB1 ()
{




    int vectDados[6];
    int salir = 1;
    string vJugadores[2];





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




