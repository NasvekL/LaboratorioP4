#include "../../include/Clases/Leccion.h"

void Leccion::setTema(string tema) {
    this->tema = tema;
}

void Leccion::setObjetivoAprendizaje(string objetivoAprendizaje) {
    this->objetivoAprendizaje = objetivoAprendizaje;
}

void Leccion::setCantidadEjercicios(int cantidadDeEjercicios) {
    this->cantidadDeEjercicios = cantidadDeEjercicios;
}

void Leccion::setNumero(int numero) {
    this->numero = numero;
}

string Leccion::getTema() {
    return tema;
}

void Leccion::addEjercicio(Ejercicio* ej) {
    ejercicios.insert(pair<int, Ejercicio*>(ej->getIdEjercicio(), ej));
    setCantidadEjercicios(getCantidadDeEjercicios() + 1);
    // Implementación de addEjercicio
    // Agrega un ejercicio al mapa de ejercicios
}
string Leccion::getObjetivoAprendizaje() {
    return objetivoAprendizaje;
}

int Leccion::getCantidadDeEjercicios() {
    return cantidadDeEjercicios;
}

int Leccion::getNumero() {
    return numero;
}

map<int, Ejercicio*> Leccion::getEjercicios(){
    //return ejercicios;
}

Leccion::~Leccion() {
    // Implementación del destructor si es necesario
}

Leccion::Leccion(string tema, string objetivoAprendizaje, int cantidadDeEjercicios, int numero) {
    this->tema = tema;
    this->objetivoAprendizaje = objetivoAprendizaje;
    this->cantidadDeEjercicios = cantidadDeEjercicios;
    this->numero = numero;
}

DTEjercicio Leccion::seleccionarEj(int idEjercicio) {
    // Implementación de seleccionarEj
    // Retorna un objeto DTEjercicio según el idEjercicio proporcionado
}

void Leccion::aumentarProgreso(Estudiante e) {
    // Implementación de aumentarProgreso
    // Aumenta el progreso del estudiante en la lección actual
}

set<DTEjercicio> Leccion::ejerciciosNoAprobados(string nick) {
    // Implementación de ejerciciosNoAprobados
    // Retorna un conjunto de DTEjercicio de los ejercicios no aprobados por el estudiante con el nickname proporcionado
}
