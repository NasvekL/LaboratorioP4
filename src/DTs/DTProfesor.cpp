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
DTProfesor::~DTProfesor() {
    // Implementación del destructor
    // Puedes realizar cualquier limpieza necesaria
}

// Getters
string DTProfesor::getInstituto() {
    // Implementación del getter
    // Puedes devolver el valor del atributo instituto
}

string DTProfesor::getDescripcion() {
    // Implementación del getter
    // Puedes devolver el valor del atributo descripcion
}

string DTProfesor::getNombre() {
    // Implementación del getter
    // Puedes devolver el valor del atributo nombre
}

string DTProfesor::getContrasenia() {
    // Implementación del getter
    // Puedes devolver el valor del atributo contrasenia
}

string DTProfesor::getNickname() {
    // Implementación del getter
    // Puedes devolver el valor del atributo nickname
}