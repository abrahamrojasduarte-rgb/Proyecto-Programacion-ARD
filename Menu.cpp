//
// Created by Abraham on 2/6/2026.
//

#include "Menu.h"
void Menu::mostrarMenu() {
    int opcion;
    cout << "Bienvenido al sistema universitario\n";
    cout << "1. Iniciar sesion como administrador\n";
    cout << "2. Iniciar sesion como estudiante\n";
    cout << "3. Salir\n";
    cout << "Elija una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            iniciarSesionAdministrador();
            break;
        case 2:
            iniciarSesionEstudiante();
            break;
        case 3:
            cout << "Gracias por usar el sistema. ¡Adios!" << endl;
            break;
        default:
            cout << "Opcion no válida. Intente de nuevo." << endl;
            mostrarMenu();
            break;
    }
}
void Menu::iniciarSesionAdministrador() {
    string usuario;
    cout << "Ingrese su nombre de usuario: ";
    cin >> usuario;

    cout << "Bienvenido, administrador: " << usuario << endl;

    int opcion;
    do {
        cout << "\n--- Menu Administrador ---\n";
        cout << "1. Registrar Estudiante\n";
        cout << "2. Registrar Profesor\n";
        cout << "3. Registrar Curso\n";
        cout << "4. Eliminar Estudiante\n";
        cout << "5. Eliminar Profesor\n";
        cout << "6. Eliminar Curso\n";
        cout << "7. Mostrar Estudiantes\n";
        cout << "8. Mostrar Profesores\n";
        cout << "9. Mostrar Cursos\n";
        cout << "10. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                registrarProfesor();
                break;
            case 3:
                registrarCurso();
                break;
            case 4:
                eliminarEstudiante();
                break;
            case 5:
                eliminarProfesor();
                break;
            case 6:
                eliminarCurso();
                break;
            case 7:
                mostrarEstudiantes();
                break;
            case 8:
                mostrarProfesores();
                break;
            case 9:
                mostrarCursos();
                break;
            case 10:
                cout << "Saliendo del menú administrador...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 10);
    mostrarMenu();
}


void Menu::iniciarSesionEstudiante() {
    string usuario;
    cout << "Ingrese su nombre de usuario: ";
    cin >> usuario;

    cout << "Bienvenido, estudiante: " << usuario << endl;

    int opcion;
    do {
        cout << "\n--- Menu Estudiante ---\n";
        cout << "1. Ver Cursos Disponibles\n";
        cout << "2. Escoger Curso\n";
        cout << "3. Mostrar horario\n";
        cout << "4. Quitar curso \n ";
        cout << "5. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarCursos();
                break;
            case 2:
                escogerCurso();
                break;
            case 3:
                mostrarHorario();
            case 4:
                quitarCurso();
                break;
            case 5:
                cout << "Saliendo del menu estudiante...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);
    mostrarMenu();
}
void Menu::registrarEstudiante() {
    int cedula;
    string nombre, carrera;
    cout << "Ingrese la cedula del estudiante: ";
    cin >> cedula;
    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese la carrera del estudiante: ";
    getline(cin, carrera);
    sistema.registrarEstudiante(cedula, nombre, carrera);
}

void Menu::registrarProfesor() {
    int cedula;
    string nombre;
    cout << "Ingrese la cedula del profesor: ";
    cin >> cedula;
    cout << "Ingrese el nombre del profesor: ";
    cin.ignore();
    getline(cin, nombre);
    sistema.registrarProfesor(cedula, nombre);
}

void Menu::registrarCurso() {
    string codigo, nombre;
    int cedulaProfesor,diaC, horaC;
    cout << "Ingrese el codigo del curso: ";
    cin >> codigo;
    cout << "Ingrese el nombre del curso: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese la cedula del profesor asignado: ";
    cin >> cedulaProfesor;
    cout<<"Ingrese el dia [0-4] y hora [0-13] del curso: "<<endl;
    cin.ignore();
    cin>>diaC;
    cin>>horaC;

    Persona* persona = sistema.getListaProfesors()->buscar(cedulaProfesor);
    if (persona != nullptr && persona->esProfesor()) {
        sistema.registrarCursos(codigo, nombre, cedulaProfesor, diaC, horaC);
    } else {
        cout << "Profesor no encontrado o no es un profesor.\n";
    }
}

void Menu::mostrarEstudiantes() {
    cout << sistema.mostrarEstudiantes() << endl;
}

void Menu::mostrarProfesores() {
    cout << sistema.mostrarProfesores() << endl;
}

void Menu::mostrarCursos() {
    cout << sistema.mostrarCursos() << endl;
}

void Menu::escogerCurso() {
    int cedulaEstudiante;
    string codCurso;
    if (!sistema.hayCursosDisponibles()) {
        cout << "No hay cursos disponibles para inscribirse." << endl;
        return;
    }

    cout << "Ingrese su cedula: ";
    cin >> cedulaEstudiante;
    cout << "Ingrese el codigo del curso que desea escoger: ";
    cin >> codCurso;
    Persona* persona = sistema.getListaEstudiantes()->buscar(cedulaEstudiante);

    if (persona != nullptr && persona->esEstudiante()) {
        Curso* curso = sistema.getListaCursos()->buscarC(codCurso);
        if (curso != nullptr) {
            sistema.escogerHorario(cedulaEstudiante,curso);
            cout << "Curso escogido exitosamente.\n";
        } else {
            cout << "Curso no encontrado.\n";
        }
    } else {
        cout << "Estudiante no encontrado.\n";
    }
}
void Menu::mostrarHorario() {
    int cedulaEstudiante;
    cout << "Ingrese su cedula para ver su horario: ";
    cin >> cedulaEstudiante;

    Persona* persona = sistema.getListaEstudiantes()->buscar(cedulaEstudiante);
    if (persona != nullptr && persona->esEstudiante()) {
        Estudiante* estudiante = (Estudiante*) persona;
        cout << "Horario de " << estudiante->getNombre() << ":\n";
        cout << estudiante->mostrarHorario() << endl;
    } else {
        cout << "Estudiante no encontrado.\n";
    }
}

void Menu::guardarloEnTXT() {
    sistema.guardarDatosTXT();
}

void Menu::eliminarEstudiante() {
    int cedula;
    cout << "Ingrese la cedula del estudiante a eliminar: ";
    cin >> cedula;

    if (sistema.eliminarEstudiante(cedula)) {
        cout << "Estudiante eliminado correctamente." << endl;
    } else {
        cout << "No se pudo eliminar el estudiante. Verifique la cedula." << endl;
    }
}

void Menu::eliminarProfesor() {
    int cedula;
    cout << "Ingrese la cedula del profesor a eliminar: ";
    cin >> cedula;

    if (sistema.eliminarProfesor(cedula)) {
        cout << "Profesor eliminado correctamente." << endl;
    } else {
        cout << "No se pudo eliminar el profesor. Verifique la cedula." << endl;
    }
}

void Menu::eliminarCurso() {
    string codigo;
    cout << "Ingrese el codigo del curso a eliminar: ";
    cin >> codigo;

    if (sistema.eliminarCurso(codigo)) {
        cout << "Curso eliminado correctamente." << endl;
    } else {
        cout << "No se pudo eliminar el curso. Verifique el codigo." << endl;
    }
}
void Menu::quitarCurso() {
    int cedulaEstudiante, dia, hora;
    cout << "Ingrese su cédula: ";
    cin >> cedulaEstudiante;
    cout << "Ingrese el día (0: Lunes, 1: Martes, ...): ";
    cin >> dia;
    cout << "Ingrese la hora (0-13): ";
    cin >> hora;

    Persona* persona = sistema.getListaEstudiantes()->buscar(cedulaEstudiante);

    if (persona != nullptr && persona->esEstudiante()) {
        Estudiante* estudiante = (Estudiante*) persona;
        if (!estudiante->quitarCurso(dia, hora)) {
            cout << "No se pudo eliminar el curso de esa hora." << endl;
        }
    } else {
        cout << "Estudiante no encontrado.\n";
    }
}
