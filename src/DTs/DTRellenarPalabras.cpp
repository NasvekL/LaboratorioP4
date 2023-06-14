#include "../../include/DTs/DTRellenarPalabras.h"

string DTRellenarPalabras :: getTipo(){
    return tipo;
}
int DTRellenarPalabras :: getIdEjercicio(){
    return idEjercicio;
}

string DTRellenarPalabras :: getDescripcion(){
    return descripcion;
}

list<string> DTRellenarPalabras :: getListaDePalabras(){
    return listaDePalabras;
}

string DTRellenarPalabras :: getLetra(){
    return letra;
}

DTRellenarPalabras :: DTRellenarPalabras(string descripcion, string letra, int idEjercicio, list<string> listaDePalabras, string tipo){
    this->tipo = tipo;
    this->idEjercicio = idEjercicio;
    this->letra = letra;
    this->descripcion = descripcion;
    this->listaDePalabras = listaDePalabras;
}
