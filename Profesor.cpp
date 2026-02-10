//
// Created by Abraham on 2/6/2026.
//

#include "Profesor.h"

Profesor::Profesor() : Persona(){
}

Profesor::Profesor(string n, int c) : Persona(n, c) {
}

bool Profesor::esProfesor() {
    return true;
}

string Profesor::toString() const {
    stringstream ss;
    ss<<"Nombre: "<<this->getNombre()<<endl
        <<"Cedula: "<<this->getCedula()<<endl;
    return ss.str();
}
Profesor::~Profesor() {}