#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"
#include "credito.h"
#include "estructuras.h"
#include "LogicaDosJugadores.h"


using namespace std;





void pintar(const char* text, int posx, int posy, bool selected){

if(selected){
    rlutil::setBackgroundColor(rlutil::COLOR::MAGENTA);
}
else{
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

    rlutil::locate(posx, posy);
        cout<<text<<endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

}




void drawMenu(int P){




        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();


        rlutil::locate(48,10+P);
        cout<<char(175)<<endl;
        rlutil::locate(64,10+P);
        cout<<char(174)<<endl;

        pintar(" 2 JUGADORES ", 50, 10, P==0);
        pintar(" ESTADISTICA ", 50, 11, P==1);
        pintar(" CREDITOS ", 50, 12, P==2);
        pintar(" SALIR ", 50, 13, P==3);

}



/// Seleccion de opciones / funciones en el menu

int selectOpciones(int &P, int pY, int &salir,jugadores vJugadores[2], estatuas& estatuillas){


   switch(rlutil::getkey())
        {
        case 14:  ///ARRIBA

             rlutil::locate(48,pY+P);
            cout<<" "<<endl;
            rlutil::locate(64,pY+P);
            cout<<" "<<endl;

            if(P >0)
            {

                P--;

            }

            break;

        case 15: ///ABAJO


                rlutil::locate(48,pY+P);
                cout<<" "<<endl;
                rlutil::locate(64,pY+P);
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

               dosJugadores(vJugadores,estatuillas);

                break;


            /// ESTADISTICAS
            case 1:


                rlutil::cls();
                estadisticas(1,1,vJugadores);

                break;

            /// CREDITOS
            case 2:


                mostrarCreditos();
                rlutil::cls();

                break;


            /// SALIR
            case 3:

                int salida;

                rlutil::cls();

                rlutil::locate(40,10);
                cout<< char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
                cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
                cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
                cout<<"                                       " <<char(186)<<"                                "<<char(186)<<endl;
                cout<<"                                       " <<char(186)<<"  Esta seguro que desea salir?  "<<char(186)<<endl;
                cout<<"                                       " <<char(186)<<"                                "<<char(186)<<endl;
                cout<<"                                       " <<char(186)<<"                                "<<char(186)<<endl;
                cout<<"                                       " <<char(186)<<"   Presione enter para salir    "<<char(186)<<endl;
                cout<<"                                       " <<char(186)<<"                                "<<char(186)<<endl;
                cout<<"                                       " <<char(186)<<"Presione otra tecla para volver "<<char(186)<<endl;
                cout<<"                                       " <<char(186)<<"                                "<<char(186)<<endl;
                cout<<"                                       ";
                cout<< char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
                cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
                cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl;


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

