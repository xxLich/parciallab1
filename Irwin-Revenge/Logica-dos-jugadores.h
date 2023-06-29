#ifndef LOGICA-DOS-JUGADORES_H_INCLUDED
#define LOGICA-DOS-JUGADORES_H_INCLUDED
#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "mesa.h"
#include "mesaydados.h"

using namespace std;


/// estatuillas

bool cangrejo(int, int);

bool hormiga(int , int);

bool medusa(int, int );

bool aguila(int, int );

bool salamandra(int , int );


bool cangrejo_tres(int d1, int d2, int d3);

bool hormiga_tres(int d1 , int d2, int d3);

bool medusa_tres(int d1 , int d2, int d3);

bool aguila_tres(int d1, int d2, int d3);


















#endif // LOGICA-DOS-JUGADORES_H_INCLUDED
