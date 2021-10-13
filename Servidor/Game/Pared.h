#include <vector>
#include "Bloque.h"
#include "Bola.h"
#include "Force.h"
#include "Painter.h"
#ifndef SERVIDOR_PARED_H
#define SERVIDOR_PARED_H


class Pared {
public:
    int score;
    enum { ROWS_COUNT = 16,
        COLS_COUNT = 8 * 3 };
    enum { ANCHO = ROWS_COUNT * Bloque::ANCHO,
        ALTURA = COLS_COUNT * Bloque::ALTURA };
    Pared();
    void draw(Painter &) const;
    Force tick(const Bola &);
    int points;
public:
    typedef std::vector<Bloque> Bloques;
    Bloques bloques_;
    }
};


#endif //SERVIDOR_PARED_H
