cmake_minimum_required(VERSION 3.20)
project(Servidor)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(server SocketServer.cpp
        SocketServer.h
        Breakout.cpp
        Juego/Bloque.cpp
        Juego/Bloque.h
        Painter.cpp
        Painter.h
        Juego/Pared.cpp
        Juego/Pared.h
        Force.cpp
        Force.h
        Juego/Bola.cpp
        Juego/Bola.h
        Juego/Juego.cpp
        Juego/Juego.h
        Juego/Paleta.cpp
        Juego/Paleta.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(server ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
