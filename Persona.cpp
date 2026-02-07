//
// Created by Abraham on 2/6/2026.
//

#include "Persona.h"

Persona::Persona() {
    this->cedula = 0;
    this->nombre = "";
}

Persona::Persona(string nombre, int cedula) {
    this->cedula = cedula;
    this->nombre = nombre;
}

string Persona::getNombre() const{
    return this->nombre;
}

int Persona::getCedula() const{
    return this->cedula;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

void Persona::setCedula(int cedula) {
    this->cedula = cedula;
}

Persona::~Persona() {}

bool Persona::esProfesor() {
    return false;
}

bool Persona::esEstudiante() {
    return false;
}
