//
// Created by Abraham on 2/6/2026.
//

#ifndef PROYECTO_PROGRAMACION_ARD_PROFESOR_H
#define PROYECTO_PROGRAMACION_ARD_PROFESOR_H
#include <string>

#include "Persona.h"


class Profesor :public Persona {
public:
    Profesor();
    Profesor(string n, int c);
    ~Profesor()override;
    bool esProfesor() override;
    string toString() const override;

};


#endif //PROYECTO_PROGRAMACION_ARD_PROFESOR_H