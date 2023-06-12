#include "../../include/Clases/RellenarPalabras.h"

RellenarPalabras::RellenarPalabras(list<string> listaDePalabras, int idEjercicio, string descripcion, string letra, Leccion* Lec): Ejercicio(), listaDePalabras(listaDePalabras) {
    // Constructor de la clase RellenarPalabras
}

list<string> RellenarPalabras::getlista() {
    return listaDePalabras;
}

bool RellenarPalabras::esCorrecto(list<string> respuestas) {
    // Implementar la lógica para verificar si las respuestas son correctas
    // Comparar las respuestas con la lista de palabras esperadas
    // ...
}

void RellenarPalabras::aumentarProgreso(string estudiante) {
    // Implementar la lógica para aumentar el progreso del estudiante
    // según la resolución de este ejercicio de rellenar palabras
    // ...
}

RellenarPalabras::~RellenarPalabras() {
    // Destructor de la clase RellenarPalabras
    // Realizar cualquier limpieza de memoria u otras tareas necesarias
    // ...
}