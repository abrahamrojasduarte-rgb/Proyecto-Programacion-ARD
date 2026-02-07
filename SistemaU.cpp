//
// Created by Abraham on 2/6/2026.
//

#include "SistemaU.h"
void SistemaU::registrarEstudiante(int cedula, string nombre, string carrera) {
    Estudiante* nuevoEstudiante = new Estudiante(nombre, cedula, carrera);
    bool s = listaEstudiantes.agregarFinal(nuevoEstudiante);

    if (!s) {
        cout<<"No se pudo agregar, estudiante ya ingresado"<<endl;
    }else {
        cout<<"Agregado correctamente"<<endl;
    }
}

string SistemaU::mostrarEstudiantes() const{
    stringstream ss;
    ss << listaEstudiantes.toString();
    return ss.str();
}

void SistemaU::mostrarHorario() {

}

void SistemaU::registrarProfesor(int cedula, string nombre) {
    Profesor* nuevoProfesor = new Profesor(nombre, cedula);
    bool s = listaProfesores.agregarFinal(nuevoProfesor);

    if (!s) {
        cout<<"No se pudo agregar, profesor ya ingresado"<<endl;
    }else {
        cout<<"Si se agrego correctamente"<<endl;
    }
}

string SistemaU::mostrarProfesores()const {
    stringstream ss;
    ss << listaProfesores.toString();
    return ss.str();
}

void SistemaU::escogerHorario(int cedulaEstudiante, int dia, int hora, Curso *curso) {
    Estudiante* estudiante = (Estudiante*)listaEstudiantes.buscar(cedulaEstudiante);
    if (estudiante != nullptr) {
        estudiante->escogerHorario(dia, hora, curso);
    } else {
        cout << "Estudiante no encontrado." << endl;
    }
}

void SistemaU::registrarCursos(string codCurso, string nomCurso, Profesor *profesor, int d, int h) {
    if (profesor == nullptr) {
        cout<<"Profesor invalido"<<endl;
    }
    if (listaCursos.estaRepetidoC(codCurso)) {
        cout<<"Curso repetido, ya esta ingresado"<<endl;
    }
    Curso* verano = new Curso(codCurso,nomCurso,profesor,d,h);
    if (listaCursos.agrgarFinalC(verano)) {
        cout<<"El curso "<<nomCurso <<" ha sido anadido correctamente "<<endl;
    }else {
        cout<<"No se ha podido anadir el curso"<<endl;
    }
}

string SistemaU::mostrarCursos() const {
    stringstream ss;
    ss << listaCursos.toString();
    return ss.str();
}

bool SistemaU::hayCursosDisponibles() const {
    return listaCursos.getCantidad() > 0;
}

ListaPersona * SistemaU::getListaEstudiantes() {
    return &listaEstudiantes;
}

ListaPersona * SistemaU::getListaProfesors() {
    return &listaProfesores;
}

ListaCursos * SistemaU::getListaCursos() {
    return &listaCursos;
}

void SistemaU::guardarEstudiantesArchivo(FILE *archivo) {
    listaEstudiantes.guardarEnArchivoEstudiantes(archivo);
}

void SistemaU::guardarProfesoresArchivo(FILE *archivo) {
    listaProfesores.guardarEnArchivoProfesores(archivo);
}
