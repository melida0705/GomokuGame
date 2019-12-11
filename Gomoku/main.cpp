#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Tabla.h"
#include "Igrac.h"
#include "Game.h"
#include "global.h"

using namespace std;

bool turn;
bool gameOver;
bool move;
Direction dir;

int main()
{
    while(true){
        for(int i=0;i<30;i++)
        cout<<"#";
        cout<<endl;
        for(int i=0;i<30/2-3;i++)
            cout<<" ";
        cout<<"Gomoku"<<endl<<"Uputstvo:"<<endl<<endl;
        cout<<"\tw - pomeranje nagore \n\ts - pomeranje nadole \n\td - pomeranje u desno \n\ta - pomeranje u levo \n\t";
        cout<<"x - prekid igre \n\te - za upis u polje"<<endl<<endl;

        for(int i=0;i<30;i++)
            cout<<"#";
        cout<<endl;
        cout<<"Type y to start game"<<endl;
        char c;
        cin>>c;
        if(c=='y'){
            system("cls");
            Game game;
            game.run();
        }
        system("cls");
    }
    return 0;
}
