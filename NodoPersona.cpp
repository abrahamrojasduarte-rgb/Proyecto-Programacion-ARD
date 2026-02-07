//
// Created by Abraham on 2/6/2026.
//

#include "NodoPersona.h"

NodoPersona::NodoPersona() {
    personita = nullptr;
    siguiente = nullptr;
}

NodoPersona::NodoPersona(Persona *personita, NodoPersona *siguiente) {
    this->personita = personita;
    this->siguiente = siguiente;
}

Persona *NodoPersona::getPersonita() {
    return this-> personita;
}
void NodoPersona::setPersonita(Persona *personita) {
    this-> personita = personita;
}
void NodoPersona::setSiguiente(NodoPersona *siguiente) {
    this-> siguiente = siguiente;
}
NodoPersona *NodoPersona::getSiguiente() {
    return this->siguiente;
}

NodoPersona::~NodoPersona() {
    delete personita;
    personita = nullptr;
    siguiente = nullptr;
}
