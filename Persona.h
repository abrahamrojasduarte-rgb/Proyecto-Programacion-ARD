//
// Created by Abraham on 2/6/2026.
//

#ifndef PROYECTO_PROGRAMACION_ARD_PERSONA_H
#define PROYECTO_PROGRAMACION_ARD_PERSONA_H
#include <iostream>
#include <sstream>

using namespace std;
class Persona {
protected:
    string nombre;
    int cedula;
public:
    Persona();
    Persona(string nombre, int cedula);

    string getNombre()const;
    int getCedula()const ;
    void setNombre(string nombre);
    void setCedula(int cedula);

    virtual string toString() const =0;
    virtual ~Persona();

    virtual bool esProfesor();
    virtual bool esEstudiante();
};


#endif //PROYECTO_PROGRAMACION_ARD_PERSONA_H