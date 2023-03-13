#include "ninio.h"

string *Ninio::ListarObjetosPrestados() {
}

Ninio::Ninio() {  //constructor
}

Ninio::~Ninio() {   //desructor
}

string Ninio::getnombre() {
    return nombre;
}

void Ninio::setnombre(string nombre) {
    this->nombre=nombre;
}

string Ninio::getdireccion() {
    return direccion;
}

void Ninio::setdireccion(string direccion) {
    this->direccion=direccion;
}

string Ninio::gettelefono() {
    return telefono;
}

void Ninio::settelefono(string telefono) {
    this->telefono=telefono;
}

string Ninio::getedad() { 
    return edad;
}

void Ninio::setedad(int edad) {
    this->edad=edad;
}

string *Ninio::ListarObjetosPrestados() {
}