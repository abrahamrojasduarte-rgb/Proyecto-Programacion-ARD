//
// Created by Abraham on 2/6/2026.
//

#include "NodoCurso.h"


NodoCurso::NodoCurso(Curso *cursillo, NodoCurso *siguiente) {
    this->cursillo = cursillo;
    this->siguiente = siguiente;
}

NodoCurso::~NodoCurso() {
    delete cursillo;
    cursillo = nullptr;
    siguiente = nullptr;
}

void NodoCurso::setSiguiente(NodoCurso *siguiente) {
    this->siguiente = siguiente;
}

Curso * NodoCurso::getCurso()const {
    return this->cursillo;
}
NodoCurso* NodoCurso::getSiguiente()const {
    return this->siguiente;
}
