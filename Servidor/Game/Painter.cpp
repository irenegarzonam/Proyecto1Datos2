#include "Painter.h"
#include <GL/gl.h>
#include <cmath>
void Painter::bar(float x1, float y1, float x2, float y2){
    glBegin(GLQUADS);
    glVertex2f(x1,y1);
    glVertex2f(x2,y1);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);
    glEnd();
}
void Painter::ball(float cx, float cy){
    float r = 8;
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 40; i++){
        float beta = 2.0f * 3,1415f * float(i)/float(40);
        float x = r* cosf(beta);
        float y = r* sinf(beta);
        glVertex2f(x+cx,y+cy);
    }
    glEnd();
}

void Painter::setColor(Color color){
    static const struct{
        float r, g, b;
    }color[]=
            {
                    {1,1,0},
                    {0,1,0},
                    {1,0.5,0},
                    {1,0,0},
                    {1,1,1},
                    {0,0,0}
            };
    glColor3f(colors[color].r,
              colors[color].g,
              colors[color].b);
}