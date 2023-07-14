#ifndef LOGICADOSJUGADORES_H_INCLUDED
#define LOGICADOSJUGADORES_H_INCLUDED

#include "estructuras.h"
#include <string>


void borrarCout();
void borrarCin();

void estadisticas(int posX,int posY,jugadores[]);
void nombreJuego(int,int);
void Jugadores(int,int,jugadores[]);


void turnoJugadores(int&,int&, jugadores[]);



void evaluarSeleccionTresDados(int ,int ,jugadores [],estatuas&);
void evaluarSeleccionDosDados(int ,int ,jugadores[],estatuas&);





int seleccionarEstatuilla(estatuas&);


bool terminarExpedicion(estatuas&);

void LAB1 ();



void evaluarMaldicionAguila(jugadores[]);
bool evaluarMaldicionSalamandra(jugadores[],int);



void llenarVectorDadosJugadorUno(jugadores[]);
void llenarVectorDadosJugadorDos(jugadores[]);
void llenarVectorDadosJugadorUnoFF(jugadores[]);
void llenarVectorDadosJugadorDosFF(jugadores[]);



void jugarPorTurno(jugadores[],estatuas&);

void estatuillasDisponibles(estatuas&);

void pedirDatos(jugadores []);

void LAB1 (jugadores[],estatuas&);


void mostrarDatosJugadorUno(jugadores []);

void mostrarDatosJugadorDos(jugadores []);





bool cangrejo(int, int);

bool hormiga(int , int);

bool medusa(int, int );

bool aguila(int, int );

bool salamandra(int , int );



bool cangrejo_tres(int d1, int d2, int d3);

bool hormiga_tres(int d1 , int d2, int d3);

bool medusa_tres(int d1 , int d2, int d3);

bool aguila_tres(int d1, int d2, int d3);





void lanzarUnDadoDiezCaras(jugadores[],int);

void lanzarCincoDadosSeisCaras(jugadores[],int);

void lanzarDosDadosDiezCaras(jugadores[],int);

void lanzarTresDadosDiezCaras(jugadores[],int);

void PuntosExpedicion(int&, int&, int&, int);




bool GanarFF(int,int,int,int,int);

bool GanarFFS(int,int,int,int,int);

bool GanarFFM(int,int,int,int,int);

int EstatuillasCero(bool);

void FinalizoFF(bool ,int&, int&, bool&);

void FaseFinal(int,int,int,int,int,bool,bool,bool,bool,bool&,bool,int&,int&);





#endif // LOGICADOSJUGADORES_H_INCLUDED
