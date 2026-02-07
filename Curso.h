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
    int dia;
    int hora;
public:
    Curso(string codigo, string nombre, Profesor* profesorAsignado,int d,int h);
    ~Curso();
    string getCodigo() const;
    string getNombre() const;
    Profesor* getProfesor() const;

    void setNombre(string nombre);
    bool setProfesor(Profesor* profesor);

    string toString() const;

    int getDia() const;
    int getHora() const;
};


#endif //PROYECTO_PROGRAMACION_ARD_CURSO_H