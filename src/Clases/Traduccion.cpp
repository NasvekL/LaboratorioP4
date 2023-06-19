#include "../../include/Clases/Traduccion.h"

Traduccion::Traduccion(string solucion, int idEjercicio, string descripcion, string letra,Leccion* lec)  {
    this->solucion = solucion;
    this->setIdEjercicio(idEjercicio);
    this->setDescripcion(descripcion);
    this->setLetra(letra);
    this->setLeccion(lec);
    // Constructor de la clase Traduccion
}

string Traduccion::getSolucion() {
    return solucion;
}

bool Traduccion::esCorrectoTraduccion(string solucion) {
    // Implementar la lógica para verificar si la solución es correcta
    return (this->solucion == solucion);
}
bool Traduccion::esCorrectoRellenarPal(list<string> solucion) {
    return false;
    // Implementar la lógica para verificar si la solución es correcta
    // ...
}
void Traduccion::aumentarProgreso(string estudiante) {
    // Implementar la lógica para aumentar el progreso del estudiante
    // según la resolución de este ejercicio de traducción
    // ...
}