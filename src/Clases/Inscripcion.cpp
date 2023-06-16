#include "../../include/Clases/Inscripcion.h"

DTFecha Inscripcion::getFecha() {
    return fecha;
}

bool Inscripcion::getAprobado() {
    return aprobado;
}

int Inscripcion::getLeccionActual() {
    return leccionActual;
}

Inscripcion::Inscripcion(DTFecha fecha, Progreso* prog) {
    this->fecha = fecha;
    this->aprobado = false;
    this->leccionActual = 0;
    this->prog = prog;
    estudianteInscrito=NULL;
}

void Inscripcion::setEstudianteInscrito(Estudiante* est) {
    this->estudianteInscrito = est;
}
void Inscripcion::setInscripccionACurso(Curso* curso) {
    this->inscripccionACurso = curso;
}


Progreso* Inscripcion::getProg(){
    return prog;
}
Curso* Inscripcion::getInscriptoA(){
    return inscripccionACurso;
}
Estudiante* Inscripcion::getEstudiante(){
    return estudianteInscrito;
}

Inscripcion::~Inscripcion() {
    // Implementación del destructor si es necesario
}
