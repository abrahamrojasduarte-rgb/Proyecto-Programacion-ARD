//
// Created by Abraham on 2/6/2026.
//

#ifndef PROYECTO_PROGRAMACION_ARD_ESTUDIANTE_H
#define PROYECTO_PROGRAMACION_ARD_ESTUDIANTE_H
#include "Persona.h"
#include "Horario.h"

class Estudiante : public Persona {
private:
    string carrera;
    Horario* miHorario;
public:
    Estudiante();
    Estudiante(string, int, string carrera);
    ~Estudiante() override;
    void setCarrera(string carrera);
    string getCarrera()const;
    string toString() const override;
    bool esEstudiante() override;
    void escogerHorario(Curso* curso);
    string mostrarHorario()const;
    bool quitarCurso(int d, int h);
};


#endif //PROYECTO_PROGRAMACION_ARD_ESTUDIANTE_H