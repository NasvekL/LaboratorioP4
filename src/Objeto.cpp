#include "Objeto.h"

void Objeto::setNombre(string nombre){
    this -> Nombre = nombre;
}

void Objeto::setAnioComprado(int anio){
    this -> AnioComprado = anio;
}

void Objeto::setEstado(estado estado){
    this -> estado = estado;
}


string Objeto::getNombre(){
    return nombre;
};

int Objeto::getAnioComprado(){
    return anioComprado;
};

estado Objeto::getEstado(){
    return estado;
};
