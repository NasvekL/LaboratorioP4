#include "Objeto.h"

Objeto Objeto::setObjeto(string nombre, int anio, estado estado){
    this -> Nombre = nombre;
    this -> anioComprado = anio;
    this -> estado = estado;
}

Objeto::~Objeto(){
};

string Objeto::getNombre(){
    return nombre;
};

int Objeto::getAnioComprado(){
    return anioComprado;
};

estado Objeto::getEstado(){
    return estado;
};
