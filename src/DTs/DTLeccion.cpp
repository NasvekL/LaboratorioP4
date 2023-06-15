#include "../../include/DTs/DTLeccion.h"


// Constructor
DTLeccion::DTLeccion(int numero, int cantidadDeEjercicios, string objetivoAprendizaje, string tema) {
    // Implementación del constructor
    // Puedes asignar los valores de los parámetros a los atributos correspondientes
    this->numero = numero;
    this->cantidadDeEjercicios = cantidadDeEjercicios;
    this->objetivoAprendizaje = objetivoAprendizaje;
    this->tema = tema;
}

// Destructor
DTLeccion::~DTLeccion() {
    // Implementación del destructor
    // Puedes realizar cualquier limpieza necesaria
}

// Getters
int DTLeccion::getNumero() {
    return numero;
    // Implementación del getter
    // Puedes devolver el valor del atributo numero
}

int DTLeccion::getCantidadDeEjercicios() {
    return this->cantidadDeEjercicios;
}

string DTLeccion::getObjetivoAprendizaje() {
    return objetivoAprendizaje;
    // Implementación del getter
    // Puedes devolver el valor del atributo objetivoAprendizaje
}

string DTLeccion::getTema() {
    return tema;
    // Implementación del getter
    // Puedes devolver el valor del atributo tema
}

void DTLeccion:: setCantEj(int cant){
    this->cantidadDeEjercicios = cant;
}