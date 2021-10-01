#ifndef PROYECTO1DATOS2_BLOQUE_H
#define PROYECTO1DATOS2_BLOQUE_H
#include "Painter.h"
#include "Force.h"
#include "Bola.h"
extern int score;
extern bool deepState;
class Bloque {
public:
    Bloque(int col,int row, int type);
    enum{ANCHO = 25,ALTURA=20};
    void draw(Painter &) const;
    void destroy();
    Force tick(const Bola &);
    int points;
    bool destroyed = false;
    int timesHit = 0;
private:
    int hits;
    int type;
    float col_;
    float row_;
    void setType(int t);
    void checkDestroyed();
    int countDownTimer_;
};


#endif //PROYECTO1DATOS2_BLOQUE_H
