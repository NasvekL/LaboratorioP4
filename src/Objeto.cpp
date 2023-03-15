#include "Objeto.h"

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

Ninio* Objeto::getNinio(){
    return prestadoA;
}