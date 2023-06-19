#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"

using namespace std;


void drawMenu(int P){


    /// MENU

        rlutil::locate(38,10+P);
        cout<<char(175)<<endl;

        rlutil::locate(40,10);
        cout<<" 2 JUGADORES "<<endl;
        rlutil::locate(40,11);
        cout<<" ESTADISTICA "<<endl;
        rlutil::locate(40,12);
        cout<<" CREDITOS " <<endl;
        rlutil::locate(40,13);
        cout<<" SALIR "<<endl;

}


int selectOpciones(int &P, int pY, int &salir){



   switch(rlutil::getkey())
        {
        case 14:  ///ARRIBA

             rlutil::locate(38,pY+P);
            cout<<" "<<endl;

            if(P >0)
            {

                P--;

            }

            break;

        case 15: ///ABAJO


                rlutil::locate(38,pY+P);
                cout<<" "<<endl;


            if(P >=0 && P<3)
            {

                P++;

            }
            break;

            /// SELECCION / ENTER


        /// ENTER
        case 1:

            switch(P)
            {


            /// 2 JUGADORES
            case 0:

               dosJugadores();

                break;


            /// ESTADISTICAS
            case 1:


                // showEstadisticas();

                break;

            /// CREDITOS
            case 2:

                // showCreditos();

                break;


            /// SALIR
            case 3:

                int salida;

                rlutil::cls();

                rlutil::locate(30,15);

                cout<<"quiere salir? , presione enter para salir "<<endl;

                salida = rlutil::getkey();

                if(salida == 1){

                    salir = 0;


                }

                rlutil::cls();



               return 0 ;

                break;
            }

            break;

        }
}

