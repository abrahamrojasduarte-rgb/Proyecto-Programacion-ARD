//
// Created by Abraham on 2/6/2026.
//

#include "NodoCurso.h"

NodoCurso::NodoCurso() {
    this->cursillo = nullptr;
    this->siguiente = nullptr;
}

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

Curso * NodoCurso::getCurso() {
    return this->cursillo;
}
NodoCurso* NodoCurso::getSiguiente() {
    return this->siguiente;
}
