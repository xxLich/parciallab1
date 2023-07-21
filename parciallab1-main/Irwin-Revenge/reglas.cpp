#include <iostream>
#include "rlutil.h"
#include "reglas.h"

using namespace std;

void Bienvenida(int posX,int posY){
    Sleep(500);
    asterisco (posX, posY);
    borde(posX,posY);
}

void reglasJuego(int posX, int posY){


     rlutil::locate(40,10);
     regla1(posX,posY);
     rlutil::anykey();
     rlutil::cls();
     rlutil::locate(40,10);
     regla2(posX,posY);

}

void regla1(int posX,int posY){
    rlutil::setColor(rlutil::GREEN);
      rlutil::locate(20,5);
     cout<<"1.El juego se juega con dos jugadores."<<endl;
        rlutil::locate(20,6);
    cout<<"2.El juego consta de dos fases: Fase de Expedicion y Fase Final."<<endl;
      rlutil::locate(20,7);
      cout<<"3.Antes de comenzar la fase de expedicion, ambos jugadores deben lanzar un dado de diez"<<endl
     <<endl<<endl;
      rlutil::locate(20,8);
      cout<<"caras. El jugador que obtenga el numero mas bajo comenzara primero. En caso de empate"<<endl
      <<endl<<endl;
      rlutil::locate(20,9);
      cout<<"deben lanzar de nuevo hasta que haya un ganador."<<endl;
    rlutil::locate(20,10);
      cout<<"4.Fase de Expedicion: ";
      rlutil::locate(20,11);
    cout<<"A. El objetivo de la Fase de Expedicion es obtener estatuillas relacionadas con cinco ";
    rlutil::locate(20,12);
    cout<<"elementos: Arena, Tierra, Agua, Aire y Fuego.";
    rlutil::locate(20,13);
    cout<<"B. Los jugadores se turnan para elegir verbalmente una estatuilla que desean obtener en ";
    rlutil::locate(20,14);
    cout<<"cada turno.";
    rlutil::locate(20,15);
    cout<<"C. Cada jugador lanza dos dados de diez caras para intentar obtener la estatuilla ";
     rlutil::locate(20,16);
     cout<<"seleccionada.";
     rlutil::locate(20,17);
     cout<<"D. Si un jugador obtiene la estatuilla, la conserva y obtiene una bendicion para la Fase Final";
     rlutil::locate(20,18);
     cout<<"Sin embargo, tambien recibe una maldicion especifica para la Fase de Expedicion.";
     rlutil::locate(20,19);
     cout<<"E. Cada estatuilla tiene reglas especificas para su obtencion, y las bendiciones y ";
     rlutil::locate(20,20);
     cout<<"maldiciones correspondientes se aplican segun las reglas establecidas.";
        rlutil::locate(20,22);
        cout<<"-------------------------------------------->";
      rlutil::locate(20,23);
      cout<<"Presionar una tecla para leer la siguiente FASE";
        rlutil::locate(20,24);
        cout<<"-------------------------------------------->";

}



void regla2(int posX, int posY){
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(20,5);
    cout<<"Fase Final:";
    rlutil::locate(20,6);
    cout<<"A. La Fase Final comienza despues de que se hayan obtenido todas las estatuillas en la Fase";
    rlutil::locate(20,7);
    cout<<"B. En la Fase Final, se utilizan cinco dados de seis caras.";
    rlutil::locate(20,8);
    cout<<"C. El objetivo es obtener una escalera, donde todos los dados sean correlativos.";
    rlutil::locate(20,9);
    cout<<"D. El primer jugador en obtener una escalera sera el ganador de la Fase Final y,";
    rlutil::locate(20,10);
    cout<<"por lo tanto, del juego.";
    rlutil::locate(20,11);
    cout<<"6.Excepciones en la Fase Final:";
    rlutil::locate(20,12);
    cout<<"A. Si un jugador tiene la estatuilla de la Medusa, tambien puede ganar la Fase Final al";
    rlutil::locate(20,13);
    cout<<"obtener cinco dados iguales en lugar de una escalera.";
    rlutil::locate(20,14);
    cout<<"B. Si un jugador tiene la estatuilla de la Salamandra, puede ganar la Fase Final con una";
    rlutil::locate(20,15);
    cout<<"escalera mas corta, donde solo cuatro de los cinco dados sean correlativos.";
    rlutil::locate(20,16);
    cout<<"7.Puntos de Victoria:";
    rlutil::locate(20,17);
    cout<<"A. Al final del juego, se otorgan puntos de victoria segun los hitos alcanzados.";
    rlutil::locate(20,18);
    cout<<"B. Los hitos incluyen obtener estatuillas, ganar la Fase Final, entre otros.";
    rlutil::locate(20,19);
    cout<<"C. Tambien se restan puntos si el rival obtiene una estatuilla  ";
    rlutil::locate(20,20);
    cout<<"o se realizan lanzamientos en la Fase Final.";
    rlutil::locate(20,22);
    cout<<"-------------------------------------------->";
     rlutil::locate(20,23);
    cout<<"Precionar una tecla para ir al menu del juego";
    rlutil::locate(20,24);
    cout<<"-------------------------------------------->";


}




///BORDE
void borde (int posX,int posY){
    rlutil::setColor(rlutil::MAGENTA);
    for(int x=0;x<60;x++){
    rlutil::locate(x+posX,posY);
    cout<<char(223);
    }
    for(int x=0;x<60;x++){
    rlutil::locate(x+posX,posY+17);
    cout<<char(220);
    }
    rlutil::locate(35,19);
    cout<<"-------------------------------------------------> ";
    rlutil::locate(35,20);
    cout<<" Presionar un boton para leer las reglas del juego ";
     rlutil::locate(35,21);
    cout<<"-------------------------------------------------> ";


}


void asterisco(int posX, int posY){
    rlutil::locate(40,15);
    rlutil::setColor(rlutil::GREEN);

    /// LETRA I
    for (int x = 0; x<20; x++){
        for(int y=0;y<4;y++){
             rlutil::locate(2+posX,y+posY+2);
            cout<<char(219)<<endl;
            }
        }
            for(int x=0;x<5;x++){
        rlutil::locate(x+posX,posY+1);
        cout<<char(220);
    }
           for(int x=0;x<5;x++){
        rlutil::locate(x+posX,posY+6);
        cout<<char(223);
    }



///LETRA R

  for (int x=0;x<1;x++){

    for (int y=0;y<4;y++){

        rlutil::locate(x+posX+9,y+posY+2);
        cout<<char(219);
    }

  }

 for (int x=0;x<3;x++){
    rlutil::locate(x+posX+10,posY+2);
    cout<<char(223);

 }
for (int y=0;y<1;y++){
    rlutil::locate(posX+13,y+posY+3);
     cout<<char(219);


}

 for (int x=0;x<3;x++){
    rlutil::locate(x+posX+10,posY+4);
    cout<<char(223);

 }



  for (int x=0;x<1;x++){
    rlutil::locate(x+posX+11,posY+5);
    cout<<char(223);

 }

 for (int x=0;x<1;x++){
    rlutil::locate(x+posX+12,posY+5);
    cout<<char(220);

 }

for (int x=0;x<1;x++){
    rlutil::locate(x+posX+10,posY+4);
    cout<<char(254);

 }
 for (int x=0;x<1;x++){
    rlutil::locate(x+posX+6,posY+12);
    cout<<char(220);

 }



    /// LETRA W

  for (int x = 0; x<20; x++){
        for(int y=0;y<4;y++){
             rlutil::locate(18+posX,y+posY+2);
            cout<<char(219)<<endl;
            }
        }



  for (int x = 0; x<20; x++){
        for(int y=0;y<4;y++){
             rlutil::locate(24+posX,y+posY+2);
            cout<<char(219)<<endl;
            }
        }


  for (int x = 0; x<20; x++){
        for(int y=0;y<1;y++){
             rlutil::locate(19+posX,y+posY+5);
            cout<<char(219)<<endl;
            }
        }


  for (int x = 0; x<20; x++){
        for(int y=0;y<1;y++){
             rlutil::locate(20+posX,y+posY+4);
            cout<<char(219)<<endl;
            }
        }
 for (int x = 0; x<20; x++){
        for(int y=0;y<1;y++){
             rlutil::locate(21+posX,y+posY+3);
            cout<<char(219)<<endl;
            }
        }

         for (int x = 0; x<20; x++){
        for(int y=0;y<1;y++){
             rlutil::locate(22+posX,y+posY+4);
            cout<<char(219)<<endl;
            }
        }

            for (int x = 0; x<20; x++){
        for(int y=0;y<1;y++){
             rlutil::locate(23+posX,y+posY+5);
            cout<<char(219)<<endl;
            }
        }

    ///LETRA i

      for (int x = 0; x<20; x++){
        for(int y=0;y<4;y++){
             rlutil::locate(28+posX,y+posY+2);
            cout<<char(219)<<endl;
            }
        }

    for (int x = 0; x<20; x++){
        for(int y=0;y<1;y++){
             rlutil::locate(28+posX,y+posY+2);
            cout<<char(223)<<endl;
            }
        }


    ///LETRA N

    for(int x=0; x<20; x++){
        for (int y=0;y<4;y++){
            rlutil::locate(32+posX,y+posY+2);
            cout<<char(219);
        }}
      for(int x=0; x<3; x++){
        for (int y=0;y<1;y++){
            rlutil::locate(33+posX,y+posY+2);
            cout<<char(219);
        }}

         for(int x=0; x<3; x++){
        for (int y=0;y<1;y++){
            rlutil::locate(34+posX,y+posY+3);
            cout<<char(219);
        }}
            for(int x=0; x<3; x++){
        for (int y=0;y<1;y++){
            rlutil::locate(35+posX,y+posY+4);
            cout<<char(219);
        }
            }
        for(int x=0; x<3; x++){
        for (int y=0;y<1;y++){
            rlutil::locate(36+posX,y+posY+5);
            cout<<char(219);
        }
        }


    for(int x=0; x<20; x++){
        for (int y=0;y<4;y++){
            rlutil::locate(37+posX,y+posY+2);
            cout<<char(219);
        }}

///LETRA S


     for(int x=0;x<5;x++){
        rlutil::locate(x+posX+41,posY+2);
        cout<<char(223);
    }
         for(int y=0;y<2;y++){
        rlutil::locate(41+posX,y+posY+2);
        cout<<char(219);
    }
      for(int x=0;x<5;x++){
        rlutil::locate(x+posX+41,posY+4);
        cout<<char(223);
    }
      for(int x=0;x<5;x++){
        rlutil::locate(x+posX+41,posY+5);
        cout<<char(220);
    }
    for(int y=0;y<2;y++){
        rlutil::locate(45+posX,y+posY+4);
        cout<<char(219);


///LETRA R

  for (int x=0;x<1;x++){

    for (int y=0;y<4;y++){

        rlutil::locate(x+posX+2,y+posY+9);
        cout<<char(219);
    }

  }

 for (int x=0;x<3;x++){
    rlutil::locate(x+posX+3,posY+9);
    cout<<char(223);

 }
for (int y=0;y<1;y++){
    rlutil::locate(posX+6,y+posY+10);
     cout<<char(219);


}

 for (int x=0;x<3;x++){
    rlutil::locate(x+posX+3,posY+11);
    cout<<char(223);

 }



  for (int x=0;x<1;x++){
    rlutil::locate(x+posX+5,posY+11);
    cout<<char(223);

 }

 for (int x=0;x<1;x++){
    rlutil::locate(x+posX+3,posY+11);
    cout<<char(219);

 }
 for (int x=0;x<1;x++){
    rlutil::locate(x+posX+4,posY+12);
    cout<<char(223);

 }
for (int x=0;x<1;x++){
    rlutil::locate(x+posX+5,posY+12);
    cout<<char(254);

 }
 for (int x=0;x<1;x++){
    rlutil::locate(x+posX+6,posY+12);
    cout<<char(220);

 }


///LETRA E


for (int y=0;y<4;y++){
    rlutil::locate(posX+10,y+posY+9);
    cout<<char(219);


}
for (int x=0;x<4;x++){
    rlutil::locate(x+posX+11,posY+9);
    cout<<char(223);


}
for (int x=0;x<3;x++){
    rlutil::locate(x+posX+11,posY+11);
    cout<<char(223);


}
for (int x=0;x<4;x++){
    rlutil::locate(x+posX+11,posY+12);
    cout<<char(220);


}

///LETRA V

for (int x=0;x<1;x++){
    rlutil::locate(x+posX+18,posY+9);
    cout<<char(219);


}

for (int x=0;x<1;x++){
    rlutil::locate(x+posX+19,posY+10);
    cout<<char(219);

}
for (int x=0;x<1;x++){
    rlutil::locate(x+posX+20,posY+11);
    cout<<char(219);

}
for (int x=0;x<1;x++){
    rlutil::locate(x+posX+21,posY+12);
    cout<<char(219);

}
for (int x=0;x<1;x++){
    rlutil::locate(x+posX+22,posY+11);
    cout<<char(219);

}
for (int x=0;x<1;x++){
    rlutil::locate(x+posX+23,posY+10);
    cout<<char(219);

}

for (int x=0;x<1;x++){
    rlutil::locate(x+posX+24,posY+9);
    cout<<char(219);


}




///LETRA E


for (int y=0;y<4;y++){
    rlutil::locate(posX+28,y+posY+9);
    cout<<char(219);


}
for (int x=0;x<4;x++){
    rlutil::locate(x+posX+29,posY+9);
    cout<<char(223);


}
for (int x=0;x<3;x++){
    rlutil::locate(x+posX+29,posY+11);
    cout<<char(223);


}
for (int x=0;x<4;x++){
    rlutil::locate(x+posX+29,posY+12);
    cout<<char(220);


}


 ///LETRA N

    for(int x=0; x<20; x++){
        for (int y=0;y<4;y++){
            rlutil::locate(36+posX,y+posY+9);
            cout<<char(219);
        }}
      for(int x=0; x<3; x++){
        for (int y=0;y<1;y++){
            rlutil::locate(37+posX,y+posY+9);
            cout<<char(219);
        }}
      for(int x=0; x<3; x++){
        for (int y=0;y<1;y++){
            rlutil::locate(38+posX,y+posY+10);
            cout<<char(219);
        }}
         for(int x=0; x<3; x++){
        for (int y=0;y<1;y++){
            rlutil::locate(39+posX,y+posY+11);
            cout<<char(219);
        }}
            for(int x=0; x<3; x++){
        for (int y=0;y<1;y++){
            rlutil::locate(40+posX,y+posY+12);
            cout<<char(219);
        }
            }



    for(int x=0; x<20; x++){
        for (int y=0;y<4;y++){
            rlutil::locate(41+posX,y+posY+9);
            cout<<char(219);
        }}




 ///LETRA G


for (int y=0;y<4;y++){
    rlutil::locate(posX+45,y+posY+9);
    cout<<char(219);


}
for (int x=0;x<4;x++){
    rlutil::locate(x+posX+46,posY+9);
    cout<<char(223);


}
for (int x=0;x<2;x++){
    rlutil::locate(x+posX+48,posY+11);
    cout<<char(223);


}


for (int y=0;y<1;y++){
    rlutil::locate(posX+49,y+posY+11);
    cout<<char(219);


}
for (int x=0;x<4;x++){
    rlutil::locate(x+posX+46,posY+12);
    cout<<char(220);


}

///LETRA E


for (int y=0;y<4;y++){
    rlutil::locate(posX+54,y+posY+9);
    cout<<char(219);


}
for (int x=0;x<4;x++){
    rlutil::locate(x+posX+55,posY+9);
    cout<<char(223);


}
for (int x=0;x<3;x++){
    rlutil::locate(x+posX+55,posY+11);
    cout<<char(223);


}
for (int x=0;x<4;x++){
    rlutil::locate(x+posX+55,posY+12);
    cout<<char(220);


}


    }
}











