#include "../../include/DTs/DTTraduccion.h"

string DTTraduccion::getTipo(){
    return tipo;
}
int DTTraduccion :: getIdEjercicio(){
    return idEjercicio;
}

string DTTraduccion :: getDescripcion(){
    return descripcion;
}

string DTTraduccion :: getSolucion(){
    return solucion;
}

string DTTraduccion :: getLetra(){
    return letra;
}
int DTTraduccion :: getNumLec(){
    return numLec;
}
DTTraduccion::DTTraduccion(string descripcion, string letra, int idEjercicio, string solucion, string tipo,int numLec){
    this->tipo = tipo;
    this->idEjercicio = idEjercicio;
    this->letra = letra;
    this->descripcion = descripcion;
    this->solucion = solucion;
    this->numLec = numLec;
}

DTTraduccion::~DTTraduccion(){
}
