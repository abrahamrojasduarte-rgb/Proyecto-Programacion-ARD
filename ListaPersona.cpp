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
        return false;  // Si la persona es nula, no se puede agregar
    }

    // Verificamos si ya existe una persona con la misma cédula
    if (buscar(persona->getCedula()) != nullptr) {
        return false;  // Si ya existe, no la agregamos
    }

    NodoPersona* Phineas = new NodoPersona(persona, nullptr);
    if (estaVacia()) {
        primero = Phineas;  // Si la lista está vacía, 'primero' apunta al nuevo nodo
        ultimo = Phineas;   // 'ultimo' también apunta al nuevo nodo
    } else {
        ultimo->setSiguiente(Phineas);  // Conectamos el último nodo con el nuevo nodo
        ultimo = Phineas;  // Actualizamos 'ultimo' para que apunte al nuevo nodo
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
        delete chao->getPersonita();
        delete chao;
        cantidad--;
        return true;
    }

    NodoPersona* aux = primero;
    while (aux != nullptr && aux->getSiguiente() != nullptr) {
        if (aux->getSiguiente()->getPersonita()->getCedula() == c) {
            NodoPersona* borrar = aux->getSiguiente();
            aux->setSiguiente(borrar->getSiguiente());
            if (borrar == ultimo) {
                ultimo = aux;
            }
            delete borrar->getPersonita();
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
    while (actual!= nullptr) {
        ss<<actual->getPersonita()->toString()<<"--------------------------\n";
        actual = actual->getSiguiente();
    }
    return ss.str();
}

void ListaPersona::guardarEnArchivoProfesores(FILE *archivo) {
    NodoPersona* actual = primero;
    while (actual != nullptr) {
        if (actual->getPersonita() != nullptr && actual->getPersonita()->esProfesor()) {
            fprintf(archivo, "%s", actual->getPersonita()->toString().c_str());
        }
        actual = actual->getSiguiente();
    }
}

void ListaPersona::guardarEnArchivoEstudiantes(FILE *archivo) {
    NodoPersona* actual = primero;
    while (actual != nullptr) {
        if (actual->getPersonita() != nullptr && actual->getPersonita()->esEstudiante()) {
            fprintf (archivo, "%s", actual->getPersonita()->toString().c_str());
        }
        actual = actual->getSiguiente();
    }
}

int ListaPersona::getCantidad() const{
    return this->cantidad;
}