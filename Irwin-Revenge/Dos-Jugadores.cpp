#include <iostream>
#include "mesaydados.h"
#include "rlutil.h"
#include "estructuras.h"
#include "LogicaDosJugadores.h"
#include "lab.h"


using namespace std;


/// Funcion que corre el juego

void dosJugadores(jugadores vJugadores[2],estatuas& estatuillas)
{

    /// pide los nombres de los 2 vJugadores

    rlutil::cls();
    pedirDatos(vJugadores);
    rlutil::cls();

    /// si es LAB1 , va a la funcion predestinada
    if(vJugadores[0].nombre == "LAB1" || vJugadores[0].nombre == "lab1")
    {

        rlutil::cls();
        LAB1(vJugadores,estatuillas);


    }
    else
    {

        /// Se juega por quien empieza primero


        jugarPorTurno(vJugadores,estatuillas);


        /// contador de espera por maldicion medusa
        int contMaldicionMedusa = 0;

        /// contador de rondas
        int contRondas = 0;


        /// FASE DE EXPEDICION

        /// mientras hayan estatuillas devuelve true
        while(terminarExpedicion(estatuillas))
        {

            contRondas++;



            ///Primer jugador
            for(int i=0; i<vJugadores[0].rondas; i++)
            {


                /// si tiene la maldicion tendra que esperar 3 turnos antes de lanzar
                /// Maldicon de medusa
                if(vJugadores[0].vEstatuillasObtenidas[2] && contMaldicionMedusa <3)
                {
                    contMaldicionMedusa++;
                    break;
                }


                int seleccion;

                system("cls");

                /// MOSTRAR ESTATUILLAS DISPONIBLES
                estatuillasDisponibles(estatuillas);

                /// dibujar mesa
                mesa();

                /// mostrar datos del jugador actual
                mostrarDatosJugadorUno(vJugadores);

                /// generar dados aleatorios en el vector del jugador
                llenarVectorDadosJugadorUno(vJugadores);


                /// selecciona la estatuilla y evalua si esta disponible
                /// retorna la posicion de la estatuilla elegida
                seleccion = seleccionarEstatuilla(estatuillas);

                /// lanza 3 dados si el rival tiene la maldicion de la salamandra
                /// y sino lanza 2
                /// devuelve true si el rival tiene la maldicion

                if( evaluarMaldicionSalamandra(vJugadores,0))
                {

                    evaluarSeleccionTresDados(seleccion,0,vJugadores,estatuillas);
                }
                else
                {

                    evaluarSeleccionDosDados(seleccion,0,vJugadores,estatuillas);
                }


                Sleep(1000);

                borrarCout();
                rlutil::locate(30,25);
                rlutil::anykey("Presione una tecla para continuar");

                system("cls");


            }


            ///MALDICION AGUILA
            ///evalua si alguno de los 2 tiene la maldicion aguila
            /// el rival del que este maldecido lanza 2 veces por turno

            evaluarMaldicionAguila(vJugadores);

            /// corta el bucle si no hay mas estatuillas
            if(terminarExpedicion(estatuillas)==false)
            {
                break;
            }



            /// segundo jugador

            for(int i=0; i<vJugadores[1].rondas; i++)
            {

                /// si tiene la maldicion tendra que esperar 3 turnos antes de lanzar
                /// Maldicon de medusa
                if(vJugadores[1].vEstatuillasObtenidas[2] && contMaldicionMedusa <3)
                {
                    contMaldicionMedusa++;
                    break;
                }


                int seleccion;

                estatuillasDisponibles(estatuillas);
                mesa();
                mostrarDatosJugadorDos(vJugadores);
                llenarVectorDadosJugadorDos(vJugadores);
                seleccion = seleccionarEstatuilla(estatuillas);

                /// lanza 3 dados si el rival tiene la maldicion de la salamandra
                /// y sino lanza 2

                if( evaluarMaldicionSalamandra(vJugadores,1))
                {

                    evaluarSeleccionTresDados(seleccion,1,vJugadores,estatuillas);
                }
                else
                {

                    evaluarSeleccionDosDados(seleccion,1,vJugadores,estatuillas);
                }


                Sleep(1000);
                borrarCout();
                rlutil::locate(30,25);
                rlutil::anykey("Presione una tecla para continuar");
                system("cls");

            }

            ///MALDICION AGUILA
            ///evalua si alguno de los 2 tiene la maldicion aguila
            /// el rival del que este maldecido lanza 2 veces por turno

            evaluarMaldicionAguila(vJugadores);

        }




        ///*********************************



        /// FASE FINAL



        rlutil::locate(40,10);
        cout<< char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
        cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
        cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
        cout<<"                                       " <<char(186)<<"                                "<<char(186)<<endl;
        cout<<"                                       " <<char(186)<<"      Empieza la Fase Final     "<<char(186)<<endl;
        cout<<"                                       " <<char(186)<<"                                "<<char(186)<<endl;
        cout<<"                                       ";
        cout<< char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
        cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
        cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl;
        Sleep(2000);



        int contHormiga = 0;
        int NumH;

        //Booleano para activar la bendicion del Cangrejo
        bool BendCangrejo=true;

        /// Evaluamos quien empieza
        int primerJugador, segundoJugador;

        /// cambia las variables de primer y segundo jugador dependiendo de quien tiene mas estatuillas obtenidas
        turnoJugadores(primerJugador,segundoJugador,vJugadores);

        //Booleando que indica el fin de la fase final
        bool FinFF=false;



        /// cuando algun jugador hace una escalera sale

        while(FinFF==false)
        {



            for(int i=0; i<1; i++)
            {
                vJugadores[primerJugador].PuntosLanz-=1;

                mesa();
                /// se muestran los datos actuales del jugador

                /// solo se ejecuta una secuencia dependiendo de los valores de las variables primerjugador y segundo jugador

                /// si tiene mas estatuillas el jugador 1
                if(primerJugador==0)
                {
                    mostrarDatosJugadorUno(vJugadores);
                    llenarVectorDadosJugadorUnoFF(vJugadores);


                }
                /// si tiene mas estatuillas el jugador 2

                if(primerJugador ==1)
                {
                    mostrarDatosJugadorDos(vJugadores);
                    llenarVectorDadosJugadorDosFF(vJugadores);
                }


                /// si no tiene estatuillas ganadas devuelve true

                bool cero1=EstatuillasCero(vJugadores[primerJugador].vEstatuillasObtenidas);

                /// lanza 5 dados del vector del primer jugador
                lanzarCincoDadosSeisCaras(vJugadores,primerJugador);



                /// mayor parte de la fase final

                FaseFinal(vJugadores,FinFF,cero1,primerJugador,contHormiga);


                /// si tiene la bendicion cangrejo
                /// juega 2 veces en la primera ronda
                if(BendCangrejo && vJugadores[primerJugador].vEstatuillasObtenidas[0] && FinFF==false)
                {
                    i=-1;
                    BendCangrejo=false;
                }

            }



///-------------

           /// por si hace escalera , sale
            if(FinFF)
            {
                break;
            }







          /// pide un numero solo una vez para poder cambir un dado por este valor

            for(int i=0; i<1; i++)
            {
                if(vJugadores[segundoJugador].vEstatuillasObtenidas[1]&&contHormiga==0)
                {
                    bool serepiteBH=false;

                    do
                    {
                        borrarCout();
                        rlutil::locate(30,25);
                        cout << "Bendicion Hormiga: Elige un numero del 1 al 6: ";
                        borrarCin();
                        rlutil::locate(30,28);
                        cin >> NumH;


                        if(NumH>0 && NumH<7)
                        {
                            contHormiga++;
                            serepiteBH=false;
                        }
                        else
                        {
                            borrarCout();
                            rlutil::locate(30,25);
                            cout << "Numero incorrecto";
                            Sleep(1500);
                            serepiteBH=true;
                        }

                    }
                    while(serepiteBH==true);


                }



                vJugadores[segundoJugador].PuntosLanz-=1;

                mesa();
                /// se muestran los datos actuales del jugador

                /// si tiene mas estatuillas el jugador 1
                if(segundoJugador==0)
                {
                    mostrarDatosJugadorUno(vJugadores);
                    llenarVectorDadosJugadorUnoFF(vJugadores);


                }


            }

            /// si tiene mas estatuillas el jugador 2
            if(segundoJugador ==1)
            {
                mostrarDatosJugadorDos(vJugadores);
                llenarVectorDadosJugadorDosFF(vJugadores);
            }
            bool cero2 =EstatuillasCero(vJugadores[segundoJugador].vEstatuillasObtenidas);

            lanzarCincoDadosSeisCaras(vJugadores,segundoJugador);


            FaseFinal(vJugadores,FinFF,cero2,segundoJugador,contHormiga,NumH);



            if(BendCangrejo && vJugadores[segundoJugador].vEstatuillasObtenidas[0] && FinFF==false)
            {
                i=-1;
                BendCangrejo=false;
            }

        }

    }


}








///***************

/// termina el else





/// mostrar tabla de puntuacion




