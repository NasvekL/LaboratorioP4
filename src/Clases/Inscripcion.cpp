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
    this->leccionActual = 1;
    this->prog = prog;
}

void Inscripcion::setEstudianteInscrito(Estudiante* est) {
    this->estudianteInscrito = est;
}
void Inscripcion::setInscripccionACurso(Curso* curso) {
    this->inscripccionACurso = curso;
}
void Inscripcion::setAprobado() {
    this->aprobado = true;
}
void Inscripcion::setLeccionActual(int leccion) {
    this->leccionActual = leccion;
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
    //if (prog != nullptr)
    //    delete this->prog;
}

void Inscripcion::conseguirInfoInscripcion(list<string> &infoInsc){
    string aprobadoString;
    if(aprobado){
        aprobadoString="si";
    }
    else{
        aprobadoString="no";
    }
    string datosInsc = estudianteInscrito->getNombre() + "\n" + "Fecha de inscripcion: " + fecha.toString() + "\n" +"aprobado: "+ aprobadoString +  "\n";
    infoInsc.push_back(datosInsc);
}