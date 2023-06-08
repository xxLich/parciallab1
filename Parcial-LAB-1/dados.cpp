#include<iostream>
#include "rlutil.h"
#include "Menu.h"
#include "dado.h"

using namespace std;



void llenarVector(int vectDados[], int tam)
{

    int dado;
    int vueltas = 0;

    while(vueltas <6)
    {

        dado = 1 + rand() % 6 -1;

        if(dado > 0 && dado <=6 )
        {

            vectDados[vueltas] = dado;

            vueltas++;
        }

    }

}


/// dibuja 6 dados con los elementos del vector

void drawSixDados(int vectDados[])
{

    for(int i=0; i<6; i++)
    {

        drawDado(vectDados[i]);

    }




}







void drawDado(int n)
{



    switch (n)
    {

   case 1:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< "       " << char(186)<<endl;
            cout << char(186)<< "   " << char(254) << "   " << char(186)<<endl;
            cout << char(186)<< "       " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;


        case 2:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< "     " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< "       " << char(186)<<endl;
            cout << char(186)<< "     " << char(254) << " " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;



        case 3:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< "     " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< "   " << char(254) << "   " << char(186)<<endl;
            cout << char(186)<< "     " << char(254) << " " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;


        case 4:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< "       " << char(186)<<endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;
        case 5:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< "   " << char(254) << "   "<< char(186)<<endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;


        case 6:
            cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187)<< endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(186)<< " " << char(254) << "   " << char(254) << " " << char(186)<<endl;
            cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188)<< endl;
            break;


    }
}





