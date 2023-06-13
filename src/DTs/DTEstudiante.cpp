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
//destructor

// Getters
string DTEstudiante::getPais() {
return pais;
}

DTFecha DTEstudiante::getNacimiento() {
    return nacimiento;// Implementación del getter
    // Puedes devolver el valor del atributo nacimiento
}

string DTEstudiante::getNickname() {
    return nickname;// Implementación del getter
    // Puedes devolver el valor del atributo nickname
}

string DTEstudiante::getContrasenia() {
    return contrasenia;// Implementación del getter
    // Puedes devolver el valor del atributo contrasenia
}

string DTEstudiante::getDescripcion() {
    return descripcion;// Implementación del getter
    // Puedes devolver el valor del atributo descripcion
}

string DTEstudiante::getNombre() {
    return nombre;// Implementación del getter
    // Puedes devolver el valor del atributo nombre
}