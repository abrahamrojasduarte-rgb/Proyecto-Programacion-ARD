//
// Created by Abraham on 2/6/2026.
//

#include "Estudiante.h"

Estudiante::Estudiante() : Persona() {
    this->carrera = "";
    this->miHorario = new Horario();
}

Estudiante::Estudiante(string n, int c, string carrera) : Persona(n, c) {
    this->carrera = carrera;
    this->miHorario = new Horario();
}

Estudiante::~Estudiante() {
    delete miHorario;
    miHorario = nullptr;
}

void Estudiante::setCarrera(string carrera) {
    this->carrera = carrera;
}

string Estudiante::getCarrera() const {
    return this->carrera;
}

string Estudiante::toString() const {
    stringstream ss;
    ss<<"Nombre: "<<this->getNombre()<<endl
        <<"Cedula: "<<this->getCedula()<<endl
        <<"Carrera: "<<this->carrera<<endl;
    return ss.str();
}

bool Estudiante::esEstudiante() {
    return true;
}

void Estudiante::escogerHorario(int d, int h, Curso *curso) {
    if (miHorario->getCurso(d,h) == nullptr) {
        if (miHorario->asignarCurso(curso,d,h)) {
            cout << "Si pudiste agregar el curso a tu horario :)" << endl;
        } else {
            cout << "Datos invalidos!!!" << endl;
        }
    } else {
        cout << "Conflicto de horario: ya hay un curso asignado en este horario." << endl;
    }
}

string Estudiante::mostrarHorario() const{
    stringstream ss;
    ss<<miHorario->toString();
    return ss.str();
}
bool Estudiante::quitarCurso(int d, int h) {
    if (miHorario->getCurso(d, h) != nullptr) {
        miHorario->asignarCurso(nullptr, d, h);
        cout << "Curso eliminado del horario!" << endl;
        return true;
    } else {
        cout << "No hay curso asignado a esa hora." << endl;
        return false;
    }
}
