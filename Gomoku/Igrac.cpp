#include "Igrac.h"
#include <conio.h>
#include "global.h"
#include <windows.h>
Igrac::Igrac()
{
    move=false;
}

void Igrac::input(){

if(_kbhit()){
        switch(_getch()){
        case 'a':dir=LEFT;move=true;
            break;
        case 'd':dir=RIGHT;move=true;
            break;
        case 'w':dir=UP;move=true;
            break;
        case 's':dir=DOWN;move=true;
            break;
            case 'x':gameOver=true;
            break;
        case 'e':dir=UPIS;move=true; break;
        }
    }


}
