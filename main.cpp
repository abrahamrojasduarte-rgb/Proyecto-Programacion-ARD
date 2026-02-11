#include <iostream>
#include "SistemaU.h"
#include "Menu.h"


using namespace std;

int main() {
     SistemaU sistema;

    cout << "Registrando estudiantes..." << endl;
    sistema.registrarEstudiante(123456789, "Juan Perez", "Ingenieria de Sistemas");
    sistema.registrarEstudiante(987654321, "Chicky", "Ciencias del movimiento humano");

    cout << "Registrando profesores..." << endl;
    sistema.registrarProfesor(11223344, "Alvaro Ramos");
    sistema.registrarProfesor(22334455, "Natalia Diaz");

    cout << "Registrando cursos..." << endl;
    sistema.registrarCursos("C001", "Calculo I", 11223344, 1, 8);
    sistema.registrarCursos("C002", "Programacion I", 22334455, 0, 2);
    sistema.registrarCursos("C003", "Ingles", 22334455, 2, 4);
    sistema.registrarCursos("C004", "General I", 22334455, 2, 4);

    cout << "\n--- Mostrar Estudiantes ---" << endl;
    cout << sistema.mostrarEstudiantes() << endl;

    cout << "\n--- Mostrar Profesores ---" << endl;
    cout << sistema.mostrarProfesores() << endl;

    cout << "\n--- Mostrar Cursos ---" << endl;
    cout << sistema.mostrarCursos() << endl;

    cout << "\n--- Estudiante escoge cursos ---" << endl;
    sistema.escogerHorario(123456789, sistema.getListaCursos()->buscarC("C001"));
    sistema.escogerHorario(123456789, sistema.getListaCursos()->buscarC("C002"));
    sistema.escogerHorario(987654321, sistema.getListaCursos()->buscarC("C003"));
    sistema.escogerHorario(987654321, sistema.getListaCursos()->buscarC("C004"));

    cout << "\n--- Mostrar Horario del Estudiante ---" << endl;
    sistema.mostrarHorario();

    cout << "\n--- Eliminar Estudiante, Profesor y Curso ---" << endl;
    sistema.eliminarEstudiante(123456789);
    sistema.eliminarProfesor(11223344);
    sistema.eliminarCurso("C004");

    cout << "\n--- Mostrar Estudiantes Despues de Eliminar ---" << endl;
    cout << sistema.mostrarEstudiantes() << endl;

    cout << "\n--- Mostrar Profesores Despues de Eliminar ---" << endl;
    cout << sistema.mostrarProfesores() << endl;

    cout << "\n--- Mostrar Cursos Despues de Eliminar ---" << endl;
    cout << sistema.mostrarCursos() << endl;

    cout << "\n--- Guardar Datos en Archivo ---" << endl;
    sistema.guardarDatosTXT();


    // Menu menumain;
    //
    // menumain.mostrarMenu();

    return 0;
};