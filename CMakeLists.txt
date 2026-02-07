cmake_minimum_required(VERSION 4.1)
project(Proyecto_Programacion_ARD)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_Programacion_ARD main.cpp
        Persona.cpp
        Persona.h
        Estudiante.cpp
        Estudiante.h
        Profesor.cpp
        Profesor.h
        NodoPersona.cpp
        NodoPersona.h
        ListaPersona.cpp
        ListaPersona.h
        Curso.cpp
        Curso.h
        NodoCurso.cpp
        NodoCurso.h
        ListaCursos.cpp
        ListaCursos.h
        Horario.cpp
        Horario.h
        SistemaU.cpp
        SistemaU.h
        Menu.cpp
        Menu.h)
