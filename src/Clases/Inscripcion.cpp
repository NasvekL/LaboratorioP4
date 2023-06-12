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

Inscripcion::Inscripcion(DTFecha fecha, bool aprobado, int leccionActual, Progreso* prog) {
    this->fecha = fecha;
    this->aprobado = aprobado;
    this->leccionActual = leccionActual;
    this->prog = prog;
}

Inscripcion::~Inscripcion() {
    // Implementación del destructor si es necesario
}
