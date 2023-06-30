#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED


#include <string>

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

    int dados[5];
    int puntos = 0;
    bool turnoPrimero = false;

    bool  bendicion[5]={0,0,0,0,0};
    int PuntosEst=0;
    int PuntosEstMas=0;
    int PuntosGan=0;
    int PuntosGanMas=0;
    int PuntosEstMenos=0;
    int PuntosLanz=0;
    int PuntosTotal=0;
    int contEstampillasP[5]={0,0,0,0,0};



};







#endif // ESTRUCTURAS_H_INCLUDED
