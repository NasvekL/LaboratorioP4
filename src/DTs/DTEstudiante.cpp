#include "../../include/DTs/DTEstudiante.h"

// Constructor
DTEstudiante::DTEstudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha nacimiento) {
    // Implementación del constructor
    // Puedes asignar los valores de los parámetros a los atributos correspondientes
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->pais = pais;
    this->nacimiento = nacimiento;
}

// Destructor
DTEstudiante::~DTEstudiante() {
    // Implementación del destructor
    // Puedes realizar cualquier limpieza necesaria
}

// Getters
string DTEstudiante::getPais() {
    // Implementación del getter
    // Puedes devolver el valor del atributo pais
}

DTFecha DTEstudiante::getNacimineto() {
    // Implementación del getter
    // Puedes devolver el valor del atributo nacimiento
}

string DTEstudiante::getNickname() {
    // Implementación del getter
    // Puedes devolver el valor del atributo nickname
}

string DTEstudiante::getContrasenia() {
    // Implementación del getter
    // Puedes devolver el valor del atributo contrasenia
}

string DTEstudiante::getDescripcion() {
    // Implementación del getter
    // Puedes devolver el valor del atributo descripcion
}

string DTEstudiante::getNombre() {
    // Implementación del getter
    // Puedes devolver el valor del atributo nombre
}