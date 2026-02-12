//
// Created by Abraham on 2/6/2026.
//

#include "Horario.h"
Horario::Horario() {
    dias = 5;
    horas = 14;
    matriz = new Curso**[dias];
    for (int i = 0; i < dias; ++i) {
        matriz[i] = new Curso*[horas];
        for (int j = 0; j < horas; ++j) {
            matriz[i][j] = nullptr;
        }
    }
}

Horario::~Horario() {
    for (int i = 0; i < dias; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Horario::liberarMemoria() {
    if (matriz != nullptr) {
        for (int i = 0; i < dias; ++i) {
            delete matriz[i];
        }
        delete[] matriz;
        matriz = nullptr;
    }
}
bool Horario::indicesValidos(int dia, int hora) const{
    return (dia >= 0 && dia < dias && hora >= 0 && hora < horas);
}
bool Horario::asignarCurso(Curso *curso, int dia, int hora) {
    if (!indicesValidos(dia, hora)) {
        return false;
    }

    if (curso == nullptr) {
        matriz[dia][hora] = nullptr;
        return true;
    }

    if (matriz[dia][hora] != nullptr) {
        cout << "Horario ocupado: Ya hay un curso asignado a este día y hora." << endl;
        return false;
    }
    matriz[dia][hora] = curso;
    return true;
}

Curso * Horario::getCurso(int dia, int hora) const {
    if (indicesValidos(dia, hora)) {
        return matriz[dia][hora];
    }
    return nullptr;
}

string Horario::toString() const {
    stringstream ss;
    string diasDeSemana[5] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};
    string horasParaCursos[14] = {"7:00-8:00 a.m - ", "8:00-9:00 a.m - ", "9:00-10:00 a.m - ", "10:00-11:00 a.m - ", "11:00-12:00 a.m - ",
                                  "12:00-1:00 p.m - ","1:00-2:00 p.m - ", "2:00-3:00 p.m - ", "3:00-4:00 p.m - ", "4:00-5:00 p.m - ",
                                  "5:00-6:00 p.m - ", "6:00-7:00 p.m - ","7:00-8:00 p.m - ", "8:00-9:00 p.m - "};
    for (int i = 0; i < dias; ++i) {
        ss << diasDeSemana[i]<<endl;
        for (int j = 0; j < horas; ++j) {
            ss << horasParaCursos[j];
            if (matriz[i][j] == nullptr) {
                ss<<"Libre "<<endl;
            }else {
                ss<<matriz[i][j]->getCodigo()<<endl;
            }
        }
    }
    return ss.str();
}