//
// Created by Abraham on 2/6/2026.
//

#ifndef PROYECTO_PROGRAMACION_ARD_CURSO_H
#define PROYECTO_PROGRAMACION_ARD_CURSO_H
#include <iostream>
#include "Profesor.h"

using namespace std;
class Curso {
private:
    string codigo;
    string nombre;
    Profesor *profesorAsignado;
public:
    Curso(string codigo, string nombre, Profesor* profesorAsignado);
    ~Curso();
    string getCodigo() const;
    string getNombre() const;
    Profesor* getProfesor() const;

    void setNombre(string nombre);
    bool setProfesor(Profesor* profesor);

    string toString() const;
};


#endif //PROYECTO_PROGRAMACION_ARD_CURSO_H