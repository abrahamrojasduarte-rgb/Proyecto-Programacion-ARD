//
// Created by Abraham on 2/6/2026.
//

#ifndef PROYECTO_PROGRAMACION_ARD_NODOPERSONA_H
#define PROYECTO_PROGRAMACION_ARD_NODOPERSONA_H
#include "Persona.h"


class NodoPersona {
private:
    NodoPersona * siguiente;
    Persona * personita;
public:
    NodoPersona();
    NodoPersona(Persona * personita, NodoPersona * siguiente);
    void setPersonita(Persona * personita);
    void setSiguiente(NodoPersona * personita);
    Persona * getPersonita();
    NodoPersona * getSiguiente();
    ~NodoPersona();
};


#endif //PROYECTO_PROGRAMACION_ARD_NODOPERSONA_H
