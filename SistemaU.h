//
// Created by Abraham on 2/6/2026.
//

#ifndef PROYECTO_PROGRAMACION_ARD_SISTEMAU_H
#define PROYECTO_PROGRAMACION_ARD_SISTEMAU_H
#include "Persona.h"
#include "ListaPersona.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "ListaCursos.h"

class SistemaU {
private:
    ListaPersona listaEstudiantes;
    ListaPersona listaProfesores;
    ListaCursos listaCursos;
public:

    void registrarEstudiante(int cedula, string nombre, string carrera);
    string mostrarEstudiantes()const;
    void mostrarHorario();

    void registrarProfesor(int cedulaP, string nombre);
    string mostrarProfesores() const;
    void escogerHorario(int cedulaEstudiante, Curso* curso);

    void registrarCursos( string codCurso, string nomCurso, int, int, int);
    string mostrarCursos() const;
    bool hayCursosDisponibles()const;

    ListaPersona* getListaEstudiantes();
    ListaPersona* getListaProfesors();
    ListaCursos* getListaCursos();

    bool eliminarEstudiante(int cedula);
    bool eliminarProfesor(int cedula);
    bool eliminarCurso(string codCurso);

    void guardarDatosTXT();
};


#endif //PROYECTO_PROGRAMACION_ARD_SISTEMAU_H