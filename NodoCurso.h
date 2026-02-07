//
// Created by Abraham on 2/6/2026.
//

#ifndef PROYECTO_PROGRAMACION_ARD_NODOCURSO_H
#define PROYECTO_PROGRAMACION_ARD_NODOCURSO_H
#include "Curso.h"


class NodoCurso {
private:
    NodoCurso *siguiente;
    Curso* cursillo;
public:
    NodoCurso();
    NodoCurso(Curso* cursillo, NodoCurso *siguiente);
    ~NodoCurso();
    void setSiguiente(NodoCurso* siguiente);
    NodoCurso* getSiguiente();
    Curso* getCurso();
};


#endif //PROYECTO_PROGRAMACION_ARD_NODOCURSO_H