#include "../../include/Clases/Traduccion.h"

Traduccion::Traduccion(string solucion, int idEjercicio, string descripcion, string letra) : Ejercicio(), solucion(solucion) {
    // Constructor de la clase Traduccion
}

string Traduccion::getSolucion() {
    return solucion;
}

bool Traduccion::esCorrecto(string solucion) {
    // Implementar la lógica para verificar si la solución es correcta
    return (this->solucion == solucion);
}

void Traduccion::aumentarProgreso(string estudiante) {
    // Implementar la lógica para aumentar el progreso del estudiante
    // según la resolución de este ejercicio de traducción
    // ...
}