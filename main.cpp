#include <iostream>
#include "SistemaU.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Curso.h"
#include "Menu.h"
#include "ListaPersona.h"

using namespace std;

int main() {
    // SistemaU sistema;
    //
    // sistema.registrarEstudiante(123456789, "Juan Perez", "Ingenieria de Sistemas");
    // sistema.registrarEstudiante(987654321, "Ana Lopez", "Ciencias de la Computacion");
    //
    // Profesor* profesor1 = new Profesor("Carlos Martinez", 11223344);
    // Profesor* profesor2 = new Profesor("Maria Gomez", 22334455);
    // sistema.registrarCursos("C001", "Calculo I", profesor1);
    // sistema.registrarCursos("C002", "Programacion I", profesor2);
    //
    // cout << "\nCursos disponibles:\n";
    // cout << sistema.mostrarCursos() << endl;
    //
    // cout << "\nEstudiante escoge un curso:\n";
    // Curso* curso1 = sistema.getListaCursos()->buscarC("C001");
    // sistema.escogerHorario(123456789, 0, 2, curso1);  // Juan Perez escoge Calculo I
    //
    // cout << "\nHorario de Juan Perez:\n";
    // Estudiante* estudiante1 = (Estudiante*)sistema.getListaEstudiantes()->buscar(123456789);
    // cout << estudiante1->mostrarHorario() << endl;
    //
    // cout << "\nMostrar Estudiantes:\n";
    // cout << sistema.mostrarEstudiantes() << endl;
    //
    // cout << "\nMostrar Profesores:\n";
    // cout << sistema.mostrarProfesores() << endl;
    //
    // delete profesor1;
    // delete profesor2;
    // delete curso1;
    // delete estudiante1;

    Menu menumain;

    menumain.mostrarMenu();

    ListaPersona *actual = new ListaPersona();
    return 0;
};