#ifndef SERVIDOR_PAINTER_H
#define SERVIDOR_PAINTER_H


class Painter {
public:
    enum Color{YELLOW,GREEN,ORANGE,RED,WHITE,BLACK};
    static void bar(float x1, float y1, float x2, float y2);
    static void ball(float x, float y);
    static void setColor(Color);
};


#endif //SERVIDOR_PAINTER_H
