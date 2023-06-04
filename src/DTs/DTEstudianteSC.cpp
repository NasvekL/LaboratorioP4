#include "../../include/DTs/DTEstudianteSC.h"



// Constructor
DTEstudianteSC::DTEstudianteSC(string nickname, string nombre, string descripcion, string pais, DTFecha nacimiento) {
    // Implementación del constructor
    // Puedes asignar los valores de los parámetros a los atributos correspondientes
    this->nickname = nickname;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->pais = pais;
    this->nacimiento = nacimiento;
}

// Destructor
DTEstudianteSC::~DTEstudianteSC() {
    // Implementación del destructor
    // Puedes realizar cualquier limpieza necesaria
}

// Getters
string DTEstudianteSC::getDescripcion() {
    // Implementación del getter
    // Puedes devolver el valor del atributo descripcion
}

string DTEstudianteSC::getNickname() {
    // Implementación del getter
    // Puedes devolver el valor del atributo nickname
}

string DTEstudianteSC::getNombre() {
    // Implementación del getter
    // Puedes devolver el valor del atributo nombre
}

string DTEstudianteSC::getPais() {
    // Implementación del getter
    // Puedes devolver el valor del atributo pais
}

DTFecha DTEstudianteSC::getNacimineto() {
    // Implementación del getter
    // Puedes devolver el valor del atributo nacimiento
}