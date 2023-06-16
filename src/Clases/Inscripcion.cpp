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



Progreso* Inscripcion::getProg(){

}
Curso* Inscripcion::getInscriptoA(){

}
Estudiante* Inscripcion::getEstudiante(){

}

Inscripcion::~Inscripcion() {
    // Implementación del destructor si es necesario
}

void Inscripcion::conseguirInfoInscripcion(list<string> infoInsc){
    /*
    string datosInsc = estudiante->getNombre() + "\n" + "Fecha de inscripcion: " + fecha->to_string() + "\n" + "\n";
    infoInsc.push_back(datosInsc);
    */
}