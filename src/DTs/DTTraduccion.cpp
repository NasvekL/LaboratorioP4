#include "../../include/DTs/DTTraduccion.h"

string DTTRADUCCION :: getTipo(){
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

DTTraduccion :: DTTraduccion(string descripcion, string letra, int idEjercicio, string solucion, string tipo){
    this->tipo = tipo;
    this->idEjercicio = idEjercicio;
    this->letra = letra;
    this->descripcion = descripcion;
    this->solucion = solucion;
}
