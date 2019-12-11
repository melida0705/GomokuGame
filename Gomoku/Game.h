#ifndef GAME_H
#define GAME_H
#include "Tabla.h"
#include "Igrac.h"


class Game
{   Tabla Table;
    Igrac igrac;

    void logic();
    public:
        Game();
        void run();

};

#endif // GAME_H
