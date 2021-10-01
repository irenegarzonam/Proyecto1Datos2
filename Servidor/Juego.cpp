#include <iostream>
#include "Juego.h"
#include "Bloque.h"
#include "Paleta.h"
void Juego::draw(Painter &p) const{
    for(auto& bola:bolas ){
        bola.draw(p);
    }
    pared_.draw(p);
    paleta_.draw(p);
}

void Juego::setX(int x){
    paleta.setX(x);
}

void Juego::Set_Deep(bool state){
    deepState=state;
}

void Juego::tick(){
    for(auto& bola:bolas ){
        Force f = pared_.tick(bola);
        f += paleta.tick(bola);
        bola.tick(f);
        if(bola.y()>Pared::ALTURA){
            bola = Bola();
            bola.setDeep(0);

        }
    }
}