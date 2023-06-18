#include "../../include/Clases/Progreso.h"

bool Progreso::esCorrecto(string solucion) {
    // Implementar la lógica para verificar si la solución es correcta
    // según el progreso actual y el ejercicio correspondiente
    // ...
}

void Progreso::aumentarProgreso(string estudiante) {
    float aumento = 1 / leccionActual->getCantidadDeEjercicios();
    porcentaje=porcentaje+aumento;
}
void Progreso::setLeccionActual(Leccion* lec) {
    this->leccionActual = lec;
}
void Progreso::setPorcentajeCurso(float porce) {
    porcentajeCurso = porcentajeCurso + porce;
}
void Progreso::setPorcentaje(float porcentaje) {
    this->porcentaje = porcentaje;
}
void Progreso::setInscripcion(Inscripcion* insc) {
    this->inscripcion = insc;
}
void Progreso::agregarEjercicioResuelto(Ejercicio* e) {
    ejerciciosResueltos.push_back(e);
}
void Progreso::limpiarEjerciciosResueltos() {
    ejerciciosResueltos.clear();
}
float Progreso::getPorcentaje() {
    return porcentaje;
}
Inscripcion* Progreso::getInscripcion() {
    return inscripcion;
}
list<Ejercicio*> Progreso :: getEjerciciosResueltos(){
    return ejerciciosResueltos;
}
float Progreso ::getPorcentajeCurso(){
    return porcentajeCurso;
}
Progreso::Progreso(Leccion* lecActual): ejerciciosResueltos(){
    this->porcentajeCurso = 0;
    this->porcentaje = 0;
    this->leccionActual = lecActual;
    //this->ejerciciosResueltos = list<Ejercicio*>();
    this->inscripcion = nullptr;
}

Progreso::~Progreso() {
    // Destructor de la clase Progreso
    // Realizar cualquier limpieza de memoria u otras tareas necesarias
    // ...
}