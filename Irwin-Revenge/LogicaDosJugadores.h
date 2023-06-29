#ifndef LOGICADOSJUGADORES_H_INCLUDED
#define LOGICADOSJUGADORES_H_INCLUDED

#include "estructuras.h"


void llenarVectorDados(jugadores[]);

void seleccionarEstatuilla(int, jugadores[], estatuas);

void datosEnJuego(jugadores[]);

void jugarPorTurno(jugadores[]);

void dibujarEstatuilla(estatuas);

void pedirDatos(jugadores []);

int terminarExpedicion(estatuas);

void cambiarTurnos(jugadores []);

void LAB1 ();

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




void lanzarCincoDadosSeisCaras(jugadores,int);

void lanzarDosDadosDiezCaras(jugadores,int);

void lanzarTresDadosDiezCaras(jugadores,int);



bool TodasSonVerdaderas(jugadores);








#endif // LOGICADOSJUGADORES_H_INCLUDED
