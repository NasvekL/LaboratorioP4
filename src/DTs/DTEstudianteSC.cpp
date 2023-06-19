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

string DTEstudianteSC::getNickname() {
    return this->nickname;
}
