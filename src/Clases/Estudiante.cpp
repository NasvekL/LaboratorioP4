#include "../../include/Clases/Estudiante.h"

string Estudiante::getPais() {
    return pais;
}

DTFecha Estudiante::getNacimiento() {
    return nacimiento;
}


Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha nacimiento){
    this->pais = pais;
    this->nacimiento = nacimiento;
}

Estudiante::~Estudiante() {
    // Implementación del destructor si es necesario
}

list<DTNotificacion> Estudiante::verNotificaciones() {
    // Implementación de verNotificaciones
    // Retorna una lista de DTNotificacion
}

DTEstudiante Estudiante::getDTEstudiante() {
    // Implementación de getDTEstudiante
    // Retorna un objeto DTEstudiante
}

set<string> Estudiante::getCursosInscriptosSA() {
    // Implementación de getCursosInscriptosSA
    // Retorna un conjunto de strings
}

set<DTCurso> Estudiante::obtenDTCurso() {
    // Implementación de obtenDTCurso
    // Retorna un conjunto de DTCurso
}

set<int> Estudiante::obtenerProgreso() {
    // Implementación de obtenerProgreso
    // Retorna un conjunto de enteros
}

list<Inscripcion*> Estudiante::getInscripciones() {
    return inscripciones;
}