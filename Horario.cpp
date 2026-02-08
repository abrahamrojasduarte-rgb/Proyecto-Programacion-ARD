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
        return false;
    }
    matriz[curso->getDia()][curso->getHora()] = curso;
    return true;
}

Curso * Horario::getCurso(int dia, int hora) const {
    if (!indicesValidos(dia, hora)) {
        return nullptr;
    }
    return matriz[dia][hora];
}

string Horario::toString() const {
    stringstream ss;
    string diasDeSemana[5] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes"};
    string horasParaCursos[14] = {"7:00-8:00", "8:00-9:00", "9:00-10:00", "10:00-11:00", "11:00-12:00", "12:00-1:00",
                                  "1:00-2:00", "2:00-3:00", "3:00-4:00", "4:00-5:00", "5:00-6:00", "6:00-7:00",
                                  "7:00-8:00", "8:00-9:00"};
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