#include <iostream>
#include "mesaydados.h"
#include "rlutil.h"
#include "estructuras.h"
#include "LogicaDosJugadores.h"


using namespace std;



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

        /// Se juega por quien empieza primero


        jugarPorTurno(vJugadores);
        mesa();


        ///************************************************************************************


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
                    mostrarDatosJugadorUno(vJugadores);
                    int contAguila2=0;


                    rlutil::locate(30, 25);
                    cout << "                                             ";

                    rlutil::locate(30, 25);
                    cout << vJugadores[0].nombre <<" Selecciona una estatuilla";
                    mostrarDatosJugadorUno(vJugadores);

                    rlutil::locate(30, 27);
                    cin >> select;
                    rlutil::locate(30, 27);
                    cout << "                                             ";


                    switch (select)
                    {


                    case 1:
                        if(Mcangrejo)

                        {


                            rlutil::locate(30, 25);
                            cout << "                                             ";
                            rlutil::locate(30, 25);
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
                                dibujarEstatuilla(estatuillas);


                                /// llena los vectores de dados de los 2 jugadores
                                llenarVectorDados(vJugadores);

                                lanzarTresDadosDiezCaras(vJugadores,0);



                                if(cangrejo_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                                {
                                    vJugadores[0].vEstatuillasObtenidas[0]=true;
                                    estatuillas.vEstatuillasDisponibles[0]= false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                    dibujarEstatuilla(estatuillas);
                                    mostrarDatosJugadorDos(vJugadores);



                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Jugador "<<vJugadores[1].nombre <<"Tira un dado";

                                    llenarVectorDados(vJugadores);
                                    lanzarUnDadoDiezCaras(vJugadores,1);

                                    vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0];

                                    Mcangrejo=true;



                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Se le descontaron a "<<vJugadores[0].nombre <<"  "<< vJugadores[1].dados[0] << " puntos" << endl;
                                    tiro1=true;
                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "No ganaste la estatuilla" << endl;
                                    tiro1=true;
                                }
                                break;

                            case false:



                                /// tira jugador 1
                                mostrarDatosJugadorUno(vJugadores);


                                /// F


                                llenarVectorDados(vJugadores);

                                lanzarDosDadosDiezCaras(vJugadores,0);



                                /// si jugador 1 gano cangrejo
                                if(cangrejo(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                                {

                                    vJugadores[0].vEstatuillasObtenidas[0]=true;
                                    estatuillas.vEstatuillasDisponibles[0]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;

                                    dibujarEstatuilla(estatuillas);

                                    /// tira jugador 2
                                    mostrarDatosJugadorDos(vJugadores);


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Jugador "<<vJugadores[1].nombre<< "Tira un dado";

                                    llenarVectorDados(vJugadores);
                                    lanzarUnDadoDiezCaras(vJugadores,1);
                                    vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0];
                                    Mcangrejo=true;



                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Se le descontaron a "<< vJugadores[0].nombre << vJugadores[1].dados[0] << " puntos"<<endl;
                                    tiro1=true;
                                }
                                else
                                {


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
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

                            rlutil::locate(30, 25);
                            cout << "                                             ";
                            rlutil::locate(30, 25);
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

                                llenarVectorDados(vJugadores);

                                lanzarTresDadosDiezCaras(vJugadores,0);



                                /// si el lanzamiento anterior gana hormiga
                                if(hormiga_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                                {
                                    vJugadores[0].vEstatuillasObtenidas[1]=true;
                                    estatuillas.vEstatuillasDisponibles[1]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;

                                    dibujarEstatuilla(estatuillas);


                                    /// tira jugador 2

                                    mostrarDatosJugadorDos(vJugadores);

                                    llenarVectorDados(vJugadores);

                                    lanzarDosDadosDiezCaras(vJugadores,1);



                                    vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0]-vJugadores[1].dados[1];
                                    Mhormiga=true;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Se le descontaron a "<<vJugadores[0].nombre << vJugadores[1].dados[0] << " y " << vJugadores[1].dados[1] << " puntos"<<endl;

                                    tiro1=true;


                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "No ganaste la estatuilla" << endl;
                                    tiro1=true;
                                }
                                break;

                            case false:



                                /// tira jugador 1

                                mostrarDatosJugadorUno(vJugadores);

                                ///F

                                llenarVectorDados(vJugadores);

                                lanzarDosDadosDiezCaras(vJugadores,0);



///**

                                /// si jugador 1 gana hormiga
                                if(hormiga(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                                {

                                    vJugadores[0].vEstatuillasObtenidas[1]=true;
                                    estatuillas.vEstatuillasDisponibles[1]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;

                                    dibujarEstatuilla(estatuillas);

                                    /// tira jugador 2

                                    mostrarDatosJugadorDos(vJugadores);

                                    ///F
///***************


                                    cout << "Jugador "<< vJugadores[1].nombre <<"tira 2 dado"<<endl;

                                    llenarVectorDados(vJugadores);

                                    lanzarDosDadosDiezCaras(vJugadores,1);




                                    vJugadores[0].puntos=vJugadores[0].puntos-vJugadores[1].dados[0]-vJugadores[1].dados[1];
                                    Mhormiga=true;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Se le descontaron a "<<vJugadores[0].nombre << vJugadores[1].dados[0] << " y " << vJugadores[1].dados[1] << " puntos"<<endl;
                                    tiro1=true;
                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
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

                            rlutil::locate(30, 25);
                            cout << "                                             ";
                            rlutil::locate(30, 25);
                            cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                            tiro1=false;
                        }
                        else
                        {
                            switch (vJugadores[1].vEstatuillasObtenidas[4])
                            {
                            case true:

                                mostrarDatosJugadorUno(vJugadores);

                                llenarVectorDados(vJugadores);

                                lanzarTresDadosDiezCaras(vJugadores,0);


                                /// si jugador 1 gana medusa
                                if(medusa_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                                {


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                    vJugadores[0].vEstatuillasObtenidas[2] = true;
                                    estatuillas.vEstatuillasDisponibles[2] = false;
                                    Mmedusa=true;
                                    tiro1=true;

                                    dibujarEstatuilla(estatuillas);
                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "No ganaste la estatuilla" << endl;
                                    tiro1=true;
                                }
                                break;
                            case false:


                                /// tira jugador 1
                                mostrarDatosJugadorUno(vJugadores);

                                llenarVectorDados(vJugadores);

                                lanzarDosDadosDiezCaras(vJugadores,0);


                                /// si jugador 1 gana medusa
                                if(medusa(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                                {

                                    vJugadores[0].vEstatuillasObtenidas[2]=true;
                                    estatuillas.vEstatuillasDisponibles[2]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";

                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion" <<endl;
                                    Mmedusa=true;
                                    tiro1=true;

                                    dibujarEstatuilla(estatuillas);

                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
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

                            rlutil::locate(30, 25);
                            cout << "                                             ";
                            rlutil::locate(30, 25);
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

                                llenarVectorDados(vJugadores);
                                lanzarTresDadosDiezCaras(vJugadores,0);


                                /// si jugador 1 gana aguila
                                if(aguila_tres(vJugadores[0].dados[0], vJugadores[0].dados[1], vJugadores[0].dados[2]))
                                {


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion";

                                    vJugadores[0].vEstatuillasObtenidas[3]=true;
                                    estatuillas.vEstatuillasDisponibles[3]=false;

                                    Maguila=true;
                                    tiro1=true;

                                    dibujarEstatuilla(estatuillas);
                                }
                                else
                                {
                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "No ganaste la estatuilla" << endl;
                                    tiro1=true;
                                }
                                break;

                            case false:

                                /// tira jugador 1
                                mostrarDatosJugadorUno(vJugadores);

                                llenarVectorDados(vJugadores);
                                lanzarDosDadosDiezCaras(vJugadores,0);

                                /// si jugador 1 gana aguila
                                if(aguila(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                                {

                                    vJugadores[0].vEstatuillasObtenidas[3]=true;
                                    estatuillas.vEstatuillasDisponibles[3]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion";
                                    Maguila=true;
                                    tiro1=true;

                                    dibujarEstatuilla(estatuillas);

                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
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

                            rlutil::locate(30, 25);
                            cout << "                                             ";
                            rlutil::locate(30, 25);
                            cout << "Estatuilla ya ganada, vuelva a elegir";
                            tiro1=false;
                        }
                        else
                        {


                            /// si el jugador 2 tiene esta estatuilla
                            switch (vJugadores[1].vEstatuillasObtenidas[4])
                            {
                            case true:

                                rlutil::locate(30, 25);
                                cout << "                                             ";
                                rlutil::locate(30, 25);
                                cout << "Estatuilla ya ganada, vuelva a elegir";
                                tiro1=false;

                                break;


                            case false:

                                /// tira jugador 1
                                mostrarDatosJugadorUno(vJugadores);

                                llenarVectorDados(vJugadores);
                                lanzarDosDadosDiezCaras(vJugadores,0);

                                /// si jugador 1 gana salamandra
                                if(salamandra(vJugadores[0].dados[0], vJugadores[0].dados[1]))
                                {

                                    vJugadores[0].vEstatuillasObtenidas[4]=true;
                                    estatuillas.vEstatuillasDisponibles[4]=false;

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";

                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion";
                                    Msalamandra=true;
                                    tiro1=true;

                                    dibujarEstatuilla(estatuillas);

                                }
                                else
                                {
                                    rlutil::locate(30, 25);
                                    cout << "                                             ";

                                    rlutil::locate(30, 25);
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

                        rlutil::locate(30, 25);
                        cout << "                                             ";

                        rlutil::locate(30, 25);
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


                    rlutil::locate(30, 25);
                    cout << "                                             ";

                    rlutil::locate(30, 25);
                    cout << vJugadores[1].nombre <<" Selecciona una estatuilla";

                    rlutil::locate(30, 27);
                    cin >> select;
                    rlutil::locate(30, 27);
                    cout << "                                         ";


                    switch (select)
                    {
                    case 1:
                        if(Mcangrejo)
                        {

                            rlutil::locate(30, 25);
                            cout << "                                             ";
                            rlutil::locate(30, 25);
                            cout << "Estatuilla ya ganada, vuelva a elegir" << endl;
                            tiro2=false;

                        }
                        else
                        {
                            switch (vJugadores[0].vEstatuillasObtenidas[4])
                            {
                            case true:

                                mostrarDatosJugadorDos(vJugadores);

                                llenarVectorDados(vJugadores);

                                lanzarTresDadosDiezCaras(vJugadores,1);

                                /// si jugador 2 gana cangrejo
                                if(cangrejo_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                                {
                                    vJugadores[1].vEstatuillasObtenidas[0]=true;
                                    estatuillas.vEstatuillasDisponibles[0]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion";

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << vJugadores[0].nombre<<" Tira un dado";

                                    llenarVectorDados(vJugadores);
                                    lanzarUnDadoDiezCaras(vJugadores,0);

                                    vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0];
                                    Mcangrejo=true;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);

                                    cout << "Se le descontaron a"<<vJugadores[1].nombre<<" " << vJugadores[0].dados[0] << " puntos";
                                    tiro2=true;
                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "No ganaste la estatuilla" << endl;
                                    tiro2=true;
                                }
                                break;
                            case false:

                                llenarVectorDados(vJugadores);
                                lanzarDosDadosDiezCaras(vJugadores,1);

                                if(cangrejo(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[0]=true;
                                    estatuillas.vEstatuillasDisponibles[0]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;

                                    dibujarEstatuilla(estatuillas);

                                    mostrarDatosJugadorUno(vJugadores);





                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << vJugadores[0].nombre <<" Tira un dado";
                                    llenarVectorDados(vJugadores);
                                    lanzarUnDadoDiezCaras(vJugadores,0);

                                    cin >> vJugadores[0].dados[0];
                                    vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0];
                                    Mcangrejo=true;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Se le descontaron a"<< vJugadores[1].nombre << vJugadores[0].dados[0] << " puntos"<<endl;
                                    tiro2=true;
                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
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

                            rlutil::locate(30, 25);
                            cout << "                                             ";
                            rlutil::locate(30, 25);
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

                                llenarVectorDados(vJugadores);
                                lanzarTresDadosDiezCaras(vJugadores,1);


                                if(hormiga_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                                {
                                    vJugadores[1].vEstatuillasObtenidas[1]=true;
                                    estatuillas.vEstatuillasDisponibles[1]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                    dibujarEstatuilla(estatuillas);

                                    mostrarDatosJugadorUno;

                                    lanzarDosDadosDiezCaras(vJugadores,0);


                                    vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0]-vJugadores[0].dados[1];
                                    Mhormiga=true;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";

                                    rlutil::locate(30, 25);


                                    cout << "Se le descontaron a "<< vJugadores[1].nombre <<" "<< vJugadores[0].dados[0] << " y " << vJugadores[0].dados[1] << " puntos"<<endl;
                                    tiro2=true;
                                }
                                else
                                {


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "No ganaste la estatuilla" << endl;
                                    tiro2=true;
                                }
                                break;
                            case false:


                                llenarVectorDados(vJugadores);
                                lanzarDosDadosDiezCaras(vJugadores,1);

                                if(hormiga(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[1]=true;
                                    estatuillas.vEstatuillasDisponibles[1]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;

                                    dibujarEstatuilla(estatuillas);

                                    mostrarDatosJugadorUno(vJugadores);


                                    llenarVectorDados(vJugadores);
                                    lanzarDosDadosDiezCaras(vJugadores,0);


                                    vJugadores[1].puntos=vJugadores[1].puntos-vJugadores[0].dados[0]-vJugadores[0].dados[1];
                                    Mhormiga=true;



                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Se le descontaron a "<<vJugadores[1].nombre << vJugadores[0].dados[0] << " y " << vJugadores[0].dados[1] << " puntos"<<endl;
                                    tiro2=true;
                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
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

                            rlutil::locate(30, 25);
                            cout << "                                             ";
                            rlutil::locate(30, 25);
                            cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                            tiro2=false;
                        }
                        else
                        {
                            switch (vJugadores[0].vEstatuillasObtenidas[4])
                            {
                            case true:

                                llenarVectorDados(vJugadores);
                                lanzarTresDadosDiezCaras(vJugadores,1);


                                if(medusa_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[2]=true;
                                    estatuillas.vEstatuillasDisponibles[2]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                    Mmedusa=true;
                                    tiro2=true;

                                    dibujarEstatuilla(estatuillas);
                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "No ganaste la estatuilla" << endl;
                                    tiro2=true;
                                    tiro2=true;
                                }
                                break;
                            case false:



                                llenarVectorDados(vJugadores);
                                lanzarDosDadosDiezCaras(vJugadores,1);


                                if(medusa(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[2]=true;
                                    estatuillas.vEstatuillasDisponibles[2]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                    Mmedusa=true;
                                    tiro2=true;

                                    dibujarEstatuilla(estatuillas);

                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
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

                            rlutil::locate(30, 25);
                            cout << "                                             ";
                            rlutil::locate(30, 25);
                            cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                            tiro2=false;
                        }
                        else
                        {
                            switch (vJugadores[0].vEstatuillasObtenidas[4])
                            {
                            case true:

                                mostrarDatosJugadorDos(vJugadores);

                                llenarVectorDados(vJugadores);
                                lanzarTresDadosDiezCaras(vJugadores,1);



                                if(aguila_tres(vJugadores[1].dados[0], vJugadores[1].dados[1], vJugadores[1].dados[2]))
                                {



                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                    vJugadores[1].vEstatuillasObtenidas[3]=true;
                                    estatuillas.vEstatuillasDisponibles[3]=false;
                                    Maguila=true;
                                    tiro2=true;

                                    dibujarEstatuilla(estatuillas);
                                }
                                else
                                {


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "No ganaste la estatuilla" << endl;
                                    tiro2=true;
                                }
                                break;

                            case false:

                                llenarVectorDados(vJugadores);
                                lanzarDosDadosDiezCaras(vJugadores,1);

                                if(aguila(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[3]=true;
                                    estatuillas.vEstatuillasDisponibles[3]=false;


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                    Maguila=true;
                                    tiro2=true;

                                    dibujarEstatuilla(estatuillas);

                                }
                                else
                                {


                                    rlutil::locate(30, 25);
                                    cout << "                                             ";
                                    rlutil::locate(30, 25);
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


                            rlutil::locate(30, 25);
                            cout << "                                             ";
                            rlutil::locate(30, 25);
                            cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                            tiro2=false;
                            break;
                        }
                        else
                        {
                            switch (vJugadores[0].vEstatuillasObtenidas[4])
                            {
                            case true:



                                rlutil::locate(30, 25);
                                cout << "                                             ";
                                rlutil::locate(30, 25);
                                cout << "Estatuilla ya ganada, vuelva a elegir"<<endl;
                                tiro2=false;

                                break;

                            case false:

                                mostrarDatosJugadorDos(vJugadores);

                                llenarVectorDados(vJugadores);
                                lanzarDosDadosDiezCaras(vJugadores,1);

                                if(salamandra(vJugadores[1].dados[0], vJugadores[1].dados[1]))
                                {

                                    vJugadores[1].vEstatuillasObtenidas[4]=true;
                                    estatuillas.vEstatuillasDisponibles[4]=false;

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";

                                    rlutil::locate(30, 25);
                                    cout << "Estatuilla ganada, se activa tu maldicion"<<endl;
                                    Msalamandra=true;
                                    tiro2=true;

                                    dibujarEstatuilla(estatuillas);

                                }
                                else
                                {

                                    rlutil::locate(30, 25);
                                    cout << "                                             ";

                                    rlutil::locate(30, 25);
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

                        rlutil::locate(30, 25);
                        cout << "                                             ";

                        rlutil::locate(30, 25);
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





