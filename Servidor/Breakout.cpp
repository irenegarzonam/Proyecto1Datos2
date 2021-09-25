#include <GL/glut.h>
#include <iostream>
#include "Juego.h"
#include "Pared.h"
#include "Painter.h"
#include "SocketServer.h"
SocketServer* server;
void * serverRun(void* obj){
    try{
        server->run();
    } catch(string ex){
        cout<<ex<<endl;
    }
    pthread_exit(nullptr);
}
Juego* juego = Juego::getInstance();
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    Painter p;
    juego->draw(p);
    glutSwapBuffers();
}
void timer(int = 0){
    for(int i = 0; i<1.0/25/Bola::DT; ++i)
        juego->tick();
    display();
    glutTimerFunc(1000/25,timer,0);
}
int main(int argc, char **argv){
    server = new SocketServer;
    pthread_t thread;
    pthread_create(&thread, nullptr, serverRun, nullptr);
    pthread_detach(thread);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowsSize(Wall::ANCHO,Pared::ALTURA);
    glutCreateWindow("Breakout!");
    glClearColor(256,0,256,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentify();
    glOrtho(0,Pared::ANCHO,Pared::ALTURA,0,-1.0,1.0);
    glutDisplayFunc(display);
    timer();
    glutMainLoop();
}