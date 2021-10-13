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
    if(1-bola.x()> 0)
        result += Force(1 - bola.x(), 0);
    if (WIDTH - bola.x() -1 < 0)
        result += Force(WIDTH - bola.x() -1, 0);
    if (1 - bola.y() > 0)
        result += Force(0, 1 - bola.y());

    for (auto& brick : bricks_)
    {
        Force f = brick . tick(ball);
        result += f;
        if (f.x != 0 || f.y != 0){
            brick.timesHit++;
            brick.destroy();
            if(brick.destroyed)
                this->score = ::score;
        }


    }

    return result;)
}