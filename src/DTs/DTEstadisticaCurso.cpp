#include "../../include/DTs/DTEstadisticaCurso.h"



// Constructor
DTEstadisticaCurso::DTEstadisticaCurso(DTCurso curso, int promedioCurso) {
    // Implementación del constructor
    // Puedes asignar los valores de los parámetros a los atributos correspondientes
    this->curso = curso;
    this->promedioCurso = promedioCurso;
}

// Destructor
DTEstadisticaCurso::~DTEstadisticaCurso() {
    // Implementación del destructor
    // Puedes realizar cualquier limpieza necesaria
}

// Getter de curso
DTCurso DTEstadisticaCurso::getCurso() {
    // Implementación del getter
    // Puedes devolver el valor del atributo curso
}

// Getter de promedioCurso
int DTEstadisticaCurso::getpromedioCurso() {
    // Implementación del getter
    // Puedes devolver el valor del atributo promedioCurso
}

// Función para obtener la información del curso
DTCurso DTEstadisticaCurso::infoCurso() {
    // Implementación de la función
    // Puedes devolver la información del curso
}

// Función para obtener el grado de avance del curso
int DTEstadisticaCurso::gradoAvance() {
    // Implementación de la función
    // Puedes calcular y devolver el grado de avance del curso
}