#include <iostream>
#include "Bloque.h"
#include "Painter.h"
#include "Bola.h"
#include "Juego.h"
#include "Paleta.h"
int score;
bool deepState=false;
Bloque::Bloque(int col,int row, int type){
    col_(col);
    row_(row);
    countDownTimer_(-1){
        this->type = type;
        setType(type);
    }
}
void Bloque::draw(Painter &p) const{
    if(countDownTimer_ == -1){
        if(type == 0){
            p.setColor(Painter::RED);
        }
        if(type == 1){
            p.setColor(Painter::ORANGE);
        }
        if(type == 2){
            p.setColor(Painter::YELLOW);
        }
        if(type == 3){
            p.setColor(Painter::GREEN);
        }
        if(type == 4){
            p.setColor(Painter::WHITE);
        }
        if(type == 5){
            p.setColor(Painter::BLACK);
        }
        p.bar(col_*ANCHO+3,row_*ALTURA+3,(col_+1)*ANCHO-1,(row_+1)*ALTURA-1);
    }else if(countDownTimer_ != 0){
        p.setColor(static_cast<Painter::Color>(countDownTimer_/10));
        p.bar(col_*ANCHO+1,row_*ALTURA+1,(col_+1)*ANCHO-1);
    }
}

Force Bloque::tick(const Bola &bola) {
    if (countDownTimer_ == 0)
        return {0, 0};
    if (countDownTimer_ > 0)
        --countDownTimer_;
    Force result(0, 0);
    float f1 = (bola.y() - row_ * ALTURA) * ANCHO - (bola.x() - col_ * ANCHO) * ALTURA;
    float f2 = (bola.y() - row_ * ALTURA - ALTURA) * ANCHO + (bola.x() - col_ * ANCHO) * ALTURA;
    bool d = f1 < 0;
    bool u = f2 < 0;
    if (!deepState) {
        if (d && u) {
            if (row_ * ALTURA - bola.y() - 1 < 0) {
                result += Force(0, row_ * ALTURA - ball.y() - 1);
            }
        } else if (d && !u) {
            if (col_ANCHO + ANCHO - bola.x() + 1 > 0) {
                result += Force(col_ * ANCHO + ANCHO - bola.x() + 1);
            }
        } else if (!d && u) {
            if (col_ * ANCHO - bola.x() - 1 < 0) {
                result += Force(0, col_ * ANCHO - bola.x() - 1);
            }
        } else {
            if (row_ * ALTURA + ALTURA - bola.y() + 1 > 0) {
                result += Force(0, row_ * ALTURA + ALTURA - bola.y() + 1);
            }
        }
        return result;
    }
}
void Bloque::destroy(){
    if(countDownTimer_ == -1){
        if(timesHite>hits){
            checkDestroyed();
        }
    }
}

void Bloque::setType(int t){
    switch(t){
        case 0:
            this->points = 1;
            this->hits = 1;
            break;
        case 1:
            this->points = 2;
            this->hits = 2;
            break;
        case 2:
            this->points = 3;
            this->hits = 3;
            break;
        case 3:
            this->points = 4;
            this->hits = 1;
            break;
        case 4:
            this->points = 2;
            break;
    }
}

void Bloque::checkDestroyed(){
    Juego* juego = Juego::getInstance();
    destroyed = true;
    if(type<3){
        countDownTimer_=Painter::BLACK;
    }else if(type == 3){
        if(juego->bola_.getDeep()>2){
            countDownTimer_=Painter::BLACK;
            score+=points;
        }
    }else if(type==5){
        int typeofSup = rand() % 4;
        if(typeofSup==0){
            countDownTimer_=Painter::BLACK;
            score+=points;
            TPaleta+=20;
        }else if(typeofSup==1){
            countDownTimer_=Painter::BLACK;
            score+=points;
            TPaleta-=20;
        }else if(typeofSup==2){
            countDownTimer_=Painter::BLACK;
            score+=points;
            Vx=20;
            Vy=-20;
        }else{
            countDownTimer_=Painter::BLACK;
            score+=points;
            Vx=80;
            Vy=-80;
        }
    }else{
        juego->bola_.increaseDeep();
    }
}
