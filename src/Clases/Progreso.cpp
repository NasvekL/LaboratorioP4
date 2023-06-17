#include "../../include/Clases/Progreso.h"

bool Progreso::esCorrecto(string solucion) {
    // Implementar la lógica para verificar si la solución es correcta
    // según el progreso actual y el ejercicio correspondiente
    // ...
}

void Progreso::aumentarProgreso(string estudiante) {
    int aumento = ejerciciosResueltos.size()/leccionActual->getCantidadDeEjercicios();
}
void Progreso::setLeccionActual(Leccion* lec) {
    this->leccionActual = lec;
}
void Progreso::setPorcentajeCurso(int porcentaje) {
    porcentajeCurso += porcentaje;
}
void Progreso::setPorcentaje(int porcentaje) {
    this->porcentaje = porcentaje;
}
void Progreso::setInscripcion(Inscripcion* insc) {
    this->inscripcion = insc;
}

int Progreso::getPorcentaje() {
    return porcentaje;
}
Inscripcion* Progreso::getInscripcion() {
    return inscripcion;
}
list<Ejercicio*> Progreso :: getEjerciciosResueltos(){
    return ejerciciosResueltos;
}
int Progreso ::getPorcentajeCurso(){
    return porcentajeCurso;
}
Progreso::Progreso(Leccion* lecActual){
    this->porcentaje = 0;
    this->leccionActual = lecActual;
    this->ejerciciosResueltos = list<Ejercicio*>();
    this->inscripcion = nullptr;
}

Progreso::~Progreso() {
    // Destructor de la clase Progreso
    // Realizar cualquier limpieza de memoria u otras tareas necesarias
    // ...
}