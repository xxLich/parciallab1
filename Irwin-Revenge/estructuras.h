#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED


#include <string>

using namespace std;


struct estatuas
{

    string vEstatuillas[5] = {"1.CANGREJO","2.HORMIGA","3.MEDUSA","4.AGUILA","5.SALAMANDRA"};
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
    string vEstatuillas[5] = {"| CANGREJO |","| HORMIGA |","| MEDUSA |","| AGUILA |","| SALAMANDRA |"};
    bool vEstatuillasObtenidas[5] =
    {

        false, ///0 cangrejo
        false, ///1 hormiga
        false, ///2 medusa
        false, ///3 aguila
        false  ///4 salamandra
    };

    int dados[5];

    int rondas = 1;


    int puntos = 0;
    int PuntosEst=0;
    int PuntosEstMas=0;
    int PuntosEstMenos=0;
    int PuntosGan=0;
    int PuntosGanMas=0;
    int PuntosLanz=0;
    int PuntosCangrejo=0;
    int PuntosHormiga=0;

    int intentoCangrejo=0;
    int intentoHormiga=0;
    int intentoMedusa=0;
    int intentoAguila=0;
    int intentoSalamandra=0;



};






#endif // ESTRUCTURAS_H_INCLUDED
