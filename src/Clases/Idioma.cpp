#include "../../include/Clases/Idioma.h"

void Idioma::addIdioma() {
    // Implementación de addIdioma
    // Notificar a los observadores
}

void Idioma::setNombreIdioma(string nombreIdioma) {
    this->nombreIdioma = nombreIdioma;
}

string Idioma::getNombreIdioma() {
    return nombreIdioma;
}

string Idioma::suscribir(string nick) {
    // Implementación de suscribir
    // Retorna un string según el resultado de la suscripción
}

void Idioma::agregar(Usuario u) {
    // Implementación de agregar
    // Agregar un suscriptor a la lista de observers
}

void Idioma::eliminar(Usuario u) {
    // Implementación de eliminar
    // Eliminar un suscriptor de la lista de observers
}

set<string> Idioma::suscripciones(string nick) {
    // Implementación de suscripciones
    // Retorna un conjunto de strings con las suscripciones del usuario dado
}

Idioma::~Idioma() {
}

Idioma::Idioma() {
    // Implementación del constructor sin parámetros si es necesario
}

Idioma::Idioma(string nombreIdioma) {
    this->nombreIdioma = nombreIdioma;
}
