//
// Created by Abraham on 2/6/2026.
//

#ifndef PROYECTO_PROGRAMACION_ARD_MENU_H
#define PROYECTO_PROGRAMACION_ARD_MENU_H
#include <iostream>

#include "SistemaU.h"

using namespace std;

class Menu {
private:
    SistemaU sistema;
    void iniciarSesionAdministrador();
    void iniciarSesionEstudiante();
    void registrarEstudiante();
    void registrarProfesor();
    void registrarCurso();
    void mostrarEstudiantes();
    void mostrarProfesores();
    void mostrarCursos();
    void escogerCurso();

public:
    void mostrarMenu();
};


#endif //PROYECTO_PROGRAMACION_ARD_MENU_H