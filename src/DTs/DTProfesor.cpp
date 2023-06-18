#include "../../include/DTs/DTProfesor.h"
// Constructor
DTProfesor::DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, set<string> idiomas) {
    // Implementación del constructor
    // Puedes asignar los valores de los parámetros a los atributos correspondientes
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->instituto = instituto;
    this->idiomas = idiomas;
}

// Destructor
DTProfesor::~DTProfesor(){};


// Getters
string DTProfesor::getInstituto() {
    return instituto; // Implementación del getter
    // Puedes devolver el valor del atributo instituto
}
string DTProfesor::getDescripcion() {
    return descripcion;

}

string DTProfesor::getNombre() {
return nombre;
    // Implementación del getter
    // Puedes devolver el valor del atributo nombre
}

string DTProfesor::getContrasenia() {
    return contrasenia;
    // Implementación del getter
    // Puedes devolver el valor del atributo contrasenia
}

string DTProfesor::getNickname() {
    return nickname;// Implementación del getter
    // Puedes devolver el valor del atributo nickname
}
set<string> DTProfesor::getIdiomas() {
    return idiomas;
    // Implementación del getter
    // Puedes devolver el valor del atributo idiomas
}