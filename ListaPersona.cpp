//
// Created by Abraham on 2/6/2026.
//

#include "ListaPersona.h"
#include "NodoPersona.h"

ListaPersona::ListaPersona() {
    this-> primero = nullptr;
    this-> cantidad = 0;
    this-> ultimo = nullptr;
}

ListaPersona::~ListaPersona() {
    NodoPersona* actual = primero;
    while (actual != nullptr) {
        NodoPersona* aux = actual;
        delete aux->getPersonita();
        actual = actual->getSiguiente();
        delete aux;
    }
    primero = nullptr;
    ultimo = nullptr;
    cantidad = 0;
}

bool ListaPersona::estaVacia() {
    return primero == nullptr;
}

Persona * ListaPersona::buscar(int c) const {
    NodoPersona* actual = primero;
    while (actual != nullptr) {
        if (actual->getPersonita()->getCedula() == c) {
            return actual->getPersonita();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

bool ListaPersona::agregarFinal(Persona *persona) {
    if (persona == nullptr) {
        return false;
    }

    if (buscar(persona->getCedula()) != nullptr) {
        return false;
    }

    NodoPersona* Phineas = new NodoPersona(persona, nullptr);
    if (estaVacia()) {
        ultimo = Phineas;
        primero = Phineas;
    } else {
        ultimo->setSiguiente(Phineas);
        ultimo = Phineas;
    }
    cantidad++;

    return true;
}

bool ListaPersona::elimina(int c) {
    if (estaVacia()) {
        return false;
    }

    if (primero->getPersonita()->getCedula() == c) {
        NodoPersona* chao = primero;
        primero = primero->getSiguiente();
        if (primero == nullptr) {
            ultimo = nullptr;
        }
        delete chao;
        cantidad--;
        return true;
    }
    NodoPersona* aux = primero;
    while (aux->getSiguiente() != nullptr) {
        if (aux->getSiguiente()->getPersonita()->getCedula() == c) {
            NodoPersona* borrar = aux->getSiguiente();
            aux->setSiguiente(borrar->getSiguiente());
            if (borrar == ultimo) {
                ultimo = aux;
            }
            delete borrar;
            cantidad--;
            return true;
        }
        aux = aux->getSiguiente();
    }

    return false;
}

string ListaPersona::toString() const {
    stringstream ss;
    NodoPersona* actual = primero;
    while (actual != nullptr) {
        ss<<actual->getPersonita()->toString()<<"---------------------------------";
        actual = actual->getSiguiente();
    }
    return ss.str();
}

void ListaPersona::guardarEnArchivoProfesores(FILE *archivo) {
    NodoPersona* actual = primero;
    while (actual != nullptr) {
        if (actual->getPersonita()->esProfesor()) {
            fprintf (archivo, "%s", actual->getPersonita()->toString().c_str());
            actual = actual->getSiguiente();
        }
    }
}

void ListaPersona::guardarEnArchivoEstudiantes(FILE *archivo) {
    NodoPersona* actual = primero;
    while (actual != nullptr) {
        if (actual->getPersonita()->esEstudiante()) {
            fprintf (archivo, "%s", actual->getPersonita()->toString().c_str());
            actual = actual->getSiguiente();
        }
    }
}

int ListaPersona::getCantidad() const{
    return this->cantidad;
}