//
// Created by Abraham on 2/6/2026.
//

#ifndef PROYECTO_PROGRAMACION_ARD_LISTAPERSONA_H
#define PROYECTO_PROGRAMACION_ARD_LISTAPERSONA_H
#include "NodoPersona.h"
#include <iostream>
#include <sstream>

using namespace std;
class ListaPersona {
private:
    NodoPersona * primero;
    NodoPersona * ultimo;
    int cantidad;
public:
    ListaPersona();
    ~ListaPersona();
    bool estaVacia();
    Persona* buscar(int c) const ;
    bool agregarFinal(Persona* persona);
    bool elimina(int c);
    string toString()const;
    void guardarEnArchivoProfesores(FILE * archivo);
    void guardarEnArchivoEstudiantes(FILE * archivo);
    int getCantidad()const;
};


#endif //PROYECTO_PROGRAMACION_ARD_LISTAPERSONA_H