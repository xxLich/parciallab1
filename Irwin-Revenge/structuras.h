#ifndef STRUCTURAS_H_INCLUDED
#define STRUCTURAS_H_INCLUDED
#include <string>


struct estatuas
{

    std::string vEstatuillas[5] = {"1.cangrejo","2.hormiga","3.medusa","4.aguila","5.salamandra"};
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

    std::string nombre;
    std::string vEstatuillas[5] = {"|cangrejo|","|hormiga|","|medusa|","|aguila|","|salamandra|"};
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

    bool bendicionCangrejo = false;
    bool bendicionHormiga = false;
    bool bendicionMedusa = false;
    bool bendicionAguila = false;
    bool bendicionSalamandra = false;



};

#endif // STRUCTURAS_H_INCLUDED
