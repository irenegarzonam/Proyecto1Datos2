#include "Paleta.h"
#include "Pared.h"
#include "Painter.h"
int TPared = 200;
Paleta::Paleta(){
    x_=(Pared::ANCHO/2);
}
void Paleta::draw(Painter &p) const{
    p.setColor(Painter::WHITE);
    p.bar(x_-TPared/2,Pared::ALTURA-5,
          x_+TPared-TPared/2, Pared::ALTURA);
}
Force Paleta::tick(const Bola &bola) const{
    float s = bola.x()-x_+TPared/2;
    if(s >= 0 && s < TPared && Pared::ALTURA-1-bola.y()<0)
        return {(Pared::ALTURA-2-bola.y())*(x_-bola.x())/TPared,Pared::ALTURA-2-bola.y()};
    else
        return {0,0};
}

void Paleta::setX(int x){
    x_ = x;
}