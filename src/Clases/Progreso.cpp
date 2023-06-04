#include "../../Clases/Progreso.h"

bool Progreso::esCorrecto(string solucion) {
    // Implementar la lógica para verificar si la solución es correcta
    // según el progreso actual y el ejercicio correspondiente
    // ...
}

void Progreso::aumentarProgreso(string estudiante) {
    // Implementar la lógica para aumentar el progreso del estudiante
    // según la resolución exitosa de un ejercicio o lección
    // ...
}

void Progreso::setPorcentaje(int porcentaje) {
    this->porcentaje = porcentaje;
}

int Progreso::getPorcentaje() {
    return porcentaje;
}

Progreso::Progreso(int Porcentaje, Leccion* lec) : porcentaje(Porcentaje), leccion(lec) {
    // Constructor de la clase Progreso
}

Progreso::~Progreso() {
    // Destructor de la clase Progreso
    // Realizar cualquier limpieza de memoria u otras tareas necesarias
    // ...
}