#include "../../include/DTs/DTRellenarPalabras.h"


int DTRellenarPalabras :: getIdEjercicio(){
    return idEjercicio;
}

string DTRellenarPalabras :: getDescripcion(){
    return descripcion;
}

set<string> DTRellenarPalabras :: getListaDePalabras(){
    return listaDePalabras;
}

string DTRellenarPalabras :: getLetra(){
    return letra;
}

DTRellenarPalabras :: DTRellenarPalabras(string descripcion, string letra, int idEjercicio, set<string> listaDePalabras){
    this->idEjercicio = idEjercicio;
    this->letra = letra;
    this->descripcion = descripcion;
    this->listaDePalabras = listaDePalabras;
}
