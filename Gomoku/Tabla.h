#ifndef TABLA_H
#define TABLA_H


class Tabla
{
    public:
    int tabla[13][13];
    int width;     // Map dimensions
    int height;
    int x,y;  // Trenutna pozicija
        Tabla();
        void draw();
};

#endif // TABLA_H
