#ifndef PROYECTO1DATOS2_JUEGO_H
#define PROYECTO1DATOS2_JUEGO_H
#include <list>
#include "Painter.h"
#include "Bola.h"
#include "Pared.h"
#include "Paleta.h"
#include "Bloque.h"

class Juego {
public:
    bool finish = false;
    void draw(Painter &) const;
    void setX(int x);
    void tick();
    static Juego* getInstance();
    bool start = false;
    int nivel();
    Bola bola_;
    int timesLost = 0;
    void Set_Deep(bool state);
    Pared pared_;
private:
    std::list<Bola> bolas;
    Juego();
    int pBolas;
    inline static Juego* juegoI;
    Paleta paleta;
};


#endif //PROYECTO1DATOS2_JUEGO_H
