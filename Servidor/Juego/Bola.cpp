#include "Bola.h"
#include "../Painter.h"
#include "Pared.h"

int Vx = 60;
int Vy = -60;
Bola::Bola(): x_(Pared::ANCHO),y_(Pared::ALTURA - 4), Vx_(Vx), Vy_(Vy){}

void Bola::draw(Painter &p) const{
    p.setColor(Painter::YELLOW);
    p.ball(x_,y_);
}

void Bola::tick(Force f){
    float x = f.x;
    float y = f.y;
    const float LIM = .8;
    if (x>LIM)
        x=LIM;
    if (x<-LIM)
        x=-LIM;
    if(y>LIM)
        y=LIM;
    if(y<-LIM)
        y=-LIM;

    Vx_ += 25 * x;
    Vy_ += 25 * y;
    x_ += Vx_*DT;
    y_ += Vy_*DT;
}

void Bola::setDeep(int nivel){
    this->nivel = nivel;
}

int Bola::getDeep() const{
    return nivel;
}

void Bola::increaseDeep(){
    this->nivel+=1;
}