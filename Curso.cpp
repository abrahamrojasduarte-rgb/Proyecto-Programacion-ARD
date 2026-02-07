//
// Created by Abraham on 2/6/2026.
//

#include "Curso.h"
Curso::Curso(string codigo, string nombre, Profesor *profesorAsignado, int d, int h) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->profesorAsignado = profesorAsignado;
    this->hora = h;
    this-> dia = d;
}

Curso::~Curso() {}

string Curso::getCodigo() const {
    return this->codigo;
}

string Curso::getNombre() const {
    return this->nombre;
}

Profesor * Curso::getProfesor() const {
    return this->profesorAsignado;
}

void Curso::setNombre(string nombre) {
    this->nombre = nombre;
}

bool Curso::setProfesor(Profesor *profesor) {
    if (profesor != nullptr) {
        this->profesorAsignado = profesor;
        return true;
    }else {
        return false;
    }
}

string Curso::toString() const {
    stringstream ss;
    ss<<"Nombre :"<<this->nombre<<endl
        <<"Codigo :"<<this->codigo<<endl
        <<"Profesor :"<<this->profesorAsignado->getNombre()<<endl;
    return ss.str();
}

int Curso::getDia() const {
    return this->dia;
}

int Curso::getHora() const {
    return this->hora;
}
