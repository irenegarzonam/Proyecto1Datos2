cmake_minimum_required(VERSION 3.20)
project(Servidor)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(server SocketServer.cpp
        SocketServer.h
        Breakout.cpp
        Game/Bloque.cpp
        Game/Bloque.h
        Painter.cpp
        Painter.h
        Game/Pared.cpp
        Game/Pared.h
        Force.cpp
        Force.h
        Game/Bola.cpp
        Game/Bola.h
        Game/Juego.cpp
        Game/Juego.h
        Game/Paleta.cpp
        Game/Paleta.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(server ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
