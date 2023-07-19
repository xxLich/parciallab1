#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"
#include <string>
#include "estructuras.h"


void drawMenu(int);


int selectOpciones(int & , int, int &,jugadores[],estatuas&);

void estadisticas(int posX,int posY,jugadores[]);












///-----------------------------    FUNCIONES SECCION 2 JUGADORES

/// funcion principal
/// Corre el juego

void dosJugadores(jugadores vJugadores[2],estatuas& estatuillas);














#endif // MENU_H_INCLUDED
