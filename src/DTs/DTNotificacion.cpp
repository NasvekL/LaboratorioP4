#include "../../include/DTs/DTNotificacion.h"

// Constructor
DTNotificacion::DTNotificacion(DTCurso cursoCreado, Idioma idiomaDelCurso) {
    // Implementación del constructor
    // Puedes asignar los valores de los parámetros a los atributos correspondientes
    this->cursoCreado = cursoCreado;
    this->idiomaDelCurso = idiomaDelCurso;
}

// Destructor
DTNotificacion::~DTNotificacion() {
    // Implementación del destructor
    // Puedes realizar cualquier limpieza necesaria
}

// Getters
DTCurso DTNotificacion::getCurso() {
    // Implementación del getter
    // Puedes devolver el valor del atributo cursoCreado
}

Idioma DTNotificacion::getIdioma() {
    // Implementación del getter
    // Puedes devolver el valor del atributo idiomaDelCurso
}