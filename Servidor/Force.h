#ifndef PROYECTO1DATOS2_FORCE_H
#define PROYECTO1DATOS2_FORCE_H


struct Force {
    Force(float x, float y);
    float x, y;
    const Force &operator+=(Force f);
};


#endif //PROYECTO1DATOS2_FORCE_H
