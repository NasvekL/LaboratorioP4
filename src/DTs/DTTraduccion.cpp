#include "../../include/DTs/DTTraduccion.h"


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

DTTraduccion :: DTTraduccion(string descripcion, string letra, int idEjercicio, string solucion){
    this->idEjercicio = idEjercicio;
    this->letra = letra;
    this->descripcion = descripcion;
    this->solucion = solucion;
}
