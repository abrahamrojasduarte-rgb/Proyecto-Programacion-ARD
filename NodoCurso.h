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
    NodoCurso(Curso* curso, NodoCurso* sig);

    ~NodoCurso();

    Curso* getCurso() const;
    NodoCurso* getSiguiente() const;

    void setSiguiente(NodoCurso* sig);
};


#endif //PROYECTO_PROGRAMACION_ARD_NODOCURSO_H