//
// Created by Abraham on 2/6/2026.
//

#include "SistemaU.h"
void SistemaU::registrarEstudiante(int cedula, string nombre, string carrera) {
    Estudiante* nuevoEstudiante = new Estudiante(nombre, cedula, carrera);
    bool s = false;
    if (listaEstudiantes.agregarFinal(nuevoEstudiante)) {
        s = true;
    }

    if (!s) {
        cout<<"No se pudo agregar, estudiante ya ingresado"<<endl;
    }else {
        cout<<"Estudiante "<<nombre<<" agregado correctamente"<<endl;
    }
}

string SistemaU::mostrarEstudiantes() const{
    stringstream ss;
    if (listaEstudiantes.getCantidad() == 0) {
        ss<<"No hay estudiantes ";
    }else {
        ss << listaEstudiantes.toString();
    }
    return ss.str();
}

void SistemaU::mostrarHorario() {
    int cedulaEstudiante;
    cout << "Ingrese su cedula para ver su horario: ";
    cin >> cedulaEstudiante;

    Persona* persona = listaEstudiantes.buscar(cedulaEstudiante);

    if (persona != nullptr && persona->esEstudiante()) {
        Estudiante* estudiante = (Estudiante*)persona;
        cout << "Horario de " << estudiante->getNombre() << ":\n";
        cout << estudiante->mostrarHorario() << endl;
    } else {
        cout << "Estudiante no encontrado o no es un estudiante.\n";
    }
}

void SistemaU::registrarProfesor(int cedula, string nombre) {
    Profesor* nuevoProfesor = new Profesor(nombre, cedula);
    bool s = false;
    if (listaProfesores.agregarFinal(nuevoProfesor)) {
        s =true;
    }

    if (!s) {
        cout<<"No se pudo agregar, profesor ya ingresado"<<endl;
    }else {
        cout<<"Si se agrego  correctamente el profesor "<<nombre<<endl;
    }
}

string SistemaU::mostrarProfesores()const {
    stringstream ss;
    if (listaProfesores.getCantidad() == 0) {
        ss<<"No hay profesores ";
    }else {
        ss << listaProfesores.toString();
    }
    return ss.str();
}

void SistemaU::escogerHorario(int cedulaEstudiante, Curso *curso) {
    Estudiante* estudiante = (Estudiante*)listaEstudiantes.buscar(cedulaEstudiante);

    if (estudiante != nullptr && hayCursosDisponibles()) {
        estudiante->escogerHorario(curso);
    } else {
        cout << "Estudiante no encontrado." << endl;
    }
}

void SistemaU::registrarCursos(string codCurso, string nomCurso, int cedulaP, int d, int h) {
    if (listaCursos.estaRepetidoC(codCurso)) {
        cout << "Curso repetido, ya está ingresado." << endl;
        return;
    }

    Persona* persona = listaProfesores.buscar(cedulaP);
    if (persona == nullptr || !persona->esProfesor()) {
        cout << "Profesor inválido." << endl;
        return;
    }

    Profesor* profesor = (Profesor*)persona;

    for (int i = 0; i < listaCursos.getCantidad(); i++) {
        Curso* cursoExistente = listaCursos.buscarC(codCurso);
        if (cursoExistente != nullptr && cursoExistente->getDia() == d && cursoExistente->getHora() == h) {
            cout << "Conflicto de horario. El curso ya está asignado." << endl;
            return;
        }
    }
    Curso* nuevoCurso = new Curso(codCurso, nomCurso, profesor, d, h);
    if (listaCursos.agrgarFinalC(nuevoCurso)) {
        cout << "El curso " << nomCurso << " ha sido agregado correctamente." << endl;
    } else {
        cout << "No se ha podido agregar el curso." << endl;
    }
}

string SistemaU::mostrarCursos() const {
    stringstream ss;
    if (listaCursos.getCantidad() == 0) {
        ss<<"No hay cursos";
    }else{
        ss << listaCursos.toString();
    }
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

void SistemaU::guardarDatosTXT() {
    FILE* Archivo = fopen("ArchivoProyecto.txt", "w");
    if (!Archivo) {
        cout << "ERROR DE ARCHIVO\n";
        return;
    }

    fprintf(Archivo, "ESTUDIANTES:\n");
    listaEstudiantes.guardarEnArchivoEstudiantes(Archivo);
    fprintf(Archivo, "\nPROFESORES:\n");
    listaProfesores.guardarEnArchivoProfesores(Archivo);
    fprintf(Archivo, "\nCURSOS:\n");
    listaCursos.guardarEnArchivo(Archivo);

    fclose(Archivo);
    printf("Datos guardados exitosamente en ArchivoProyecto.txt\n");
}

bool SistemaU::eliminarEstudiante(int cedula) {
    Persona* persona = listaEstudiantes.buscar(cedula);
    if (persona != nullptr && persona->esEstudiante()) {
        if (listaEstudiantes.elimina(cedula)) {
            return true;
        } else {
            return false;
        }
    } else {
        cout << "Estudiante no encontrado." << endl;
        return false;
    }
}

bool SistemaU::eliminarProfesor(int cedula) {
    Persona* persona = listaProfesores.buscar(cedula);
    if (persona != nullptr && persona->esProfesor()) {
        NodoCurso* actual = listaCursos.getPrimero();
        while (actual != nullptr) {
            if (actual->getCurso()->getProfesor() == persona) {
                string codCurso = actual->getCurso()->getCodigo();
                if (listaCursos.eliminarC(codCurso)) {
                    cout << "Curso con codigo " << codCurso << " ligado al profesor/a " << persona->getNombre() << " eliminado." << endl;
                }
            }
            actual = actual->getSiguiente();
        }

        if (listaProfesores.elimina(cedula)) {
            return true;
        } else {
            return false;
        }
    } else {
        cout << "Profesor no encontrado." << endl;
        return false;
    }
}
bool SistemaU::eliminarCurso(string codCurso) {
    Curso* curso = listaCursos.buscarC(codCurso);
    if (curso != nullptr) {
        if (listaCursos.eliminarC(codCurso)) {
            return true;
        } else {
            return false;
        }
    } else {
        cout << "Curso no encontrado" << endl;
        return false;
    }
}
