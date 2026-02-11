//
// Created by Abraham on 2/6/2026.
//

#include "ListaCursos.h"

ListaCursos::ListaCursos() {
    ultimo = nullptr;
    cantidad = 0;
    primero = nullptr;
}

bool ListaCursos::estaVaciaC() {
    return primero == nullptr;
}

bool ListaCursos::estaRepetidoC(string codCurso) {
    NodoCurso* actual = primero;
    while (actual != nullptr) {
        if (actual->getCurso()->getCodigo()==codCurso) {
            return true;
        }
        actual=actual->getSiguiente();
    }
    return false;
}

Curso * ListaCursos::buscarC(string codCurso) {
    NodoCurso* actual = primero;
    while (actual != nullptr) {
        if (actual->getCurso()->getCodigo()==codCurso) {
            return actual->getCurso();
        }
        actual=actual->getSiguiente();
    }
    return nullptr;
}

bool ListaCursos::eliminarC(string codCurso) {
    if (estaVaciaC()) {
        return false;
    }
    if (primero->getCurso()->getCodigo()==codCurso) {
        NodoCurso* borrar = primero;
        primero = primero->getSiguiente();
        if (primero == nullptr) {
            ultimo = nullptr;
        }
        delete borrar;
        cantidad--;
        return true;
    }
    NodoCurso* actual = primero;
    while (actual != nullptr) {
        if (actual->getSiguiente()->getCurso()->getCodigo()==codCurso) {
            NodoCurso* borrar = actual->getSiguiente();
            actual->setSiguiente(borrar->getSiguiente());
            if (borrar == ultimo) {
                ultimo = actual;
            }
            delete borrar;
            cantidad--;
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

bool ListaCursos::agrgarFinalC(Curso *curso) {
    if (curso == nullptr) {
        return false;
    }
    NodoCurso* funda = new NodoCurso(curso, nullptr);

    if (estaVaciaC()) {
        primero = funda;
        ultimo = funda;
    } else {
        ultimo->setSiguiente(funda);
        ultimo = funda;
    }
    cantidad++;
    return true;
}

string ListaCursos::toString() const {
    stringstream ss;
    NodoCurso* actual = primero;
    while (actual != nullptr) {
        ss << actual->getCurso()->toString() << "----------------------"<<endl;
        actual = actual->getSiguiente();
    }
    return ss.str();
}
int ListaCursos::getCantidad() const {
    return this->cantidad;
}

ListaCursos::~ListaCursos() {
    NodoCurso* actual = primero;
    while (actual != nullptr) {
        NodoCurso* borrar = actual;
        delete actual->getCurso();
        actual = actual->getSiguiente();
        delete borrar;
    }
    primero = nullptr;
    ultimo = nullptr;
    cantidad = 0;
}

void ListaCursos::guardarEnArchivo(FILE *Archivo) {
    NodoCurso* ya = primero;
    while (ya != nullptr) {
        fprintf(Archivo,"%s", ya->getCurso()->toString().c_str());
        ya = ya->getSiguiente();
    }
}

NodoCurso * ListaCursos::getPrimero() const{
    return this->primero;
}
