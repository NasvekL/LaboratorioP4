#include "./Objeto.h"

void Objeto::setNombre(string nombre){
    this -> Nombre = nombre;
}

void Objeto::setAnioComprado(int anio){
    this -> AnioComprado = anio;
}

void Objeto::setEstado(state estado){
    this -> estado = estado;
}

string Objeto::getNombre(){
    return Nombre;
};

int Objeto::getAnioComprado(){
    return AnioComprado;
};

state Objeto::getEstado(){
    return estado;
};

void Objeto::setPrestadoA(Ninio* nene){
    this -> prestadoA = nene; 
}

Ninio* Objeto::getPrestadoA(){
    return prestadoA; 
}