//
// Created by Abraham on 2/6/2026.
//

#ifndef PROYECTO_PROGRAMACION_ARD_LISTACURSOS_H
#define PROYECTO_PROGRAMACION_ARD_LISTACURSOS_H
#include "NodoCurso.h"


class ListaCursos {
private:
    NodoCurso* primero;
    NodoCurso* ultimo;
    int cantidad;
public:
    ListaCursos();
    bool estaVaciaC();
    bool estaRepetidoC(string codCurso);
    Curso* buscarC(string codCurso);
    bool eliminarC(string codCurso);
    bool agrgarFinalC(Curso* curso);
    string toString()const;
    int getCantidad()const;
    ~ListaCursos();
    void guardarEnArchivo(FILE* Archivo);
    NodoCurso* getPrimero()const;
};


#endif //PROYECTO_PROGRAMACION_ARD_LISTACURSOS_H