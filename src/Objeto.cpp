#include "Objeto.h";

Objeto Objeto::setObjeto(string nombre, int anio, estado estado){
    this -> nombre = nombre;
    this -> anio = anio;
    this -> estado = estado;
}

string Objeto::getNombre(){
    return nombre;
}

int Objeto::getAnioComprado(){
    return anioComprado;
}

estado Objeto::getEstado(){
    return estado;
}

string::toString(){

};