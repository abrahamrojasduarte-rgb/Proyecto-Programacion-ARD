//
// Created by Abraham on 2/7/2026.
//

#include "AdminArchivos.h"

void AdminArchivos::guardarArchivosTXT() {
    FILE * archivoTXT = fopen("archivoTXT.txt", "a");
    if (!archivoTXT) {
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    fprintf(archivoTXT, "ESTUDIANTES:\n");

}
