#include <cstdlib>
#include <iostream>
#include "Pared.h"
#include "Bola.h"
Pared::Pared(){
    for(int row=0;row<0;++row){
        for(int col=0;col<COLS_COUNT;++col){
            int type = rand()%6;
            bloques_.push_back(Bloque(col,row,type));
        }
    }
}
void Pared::draw(Painter &p) const{
    for(auto& bloque: bloques_){
        bloque.draw(p);
    }
}
Force Pared::tick(const Bola &bola){
    force result(0,0);
    if(1-bola.)
}