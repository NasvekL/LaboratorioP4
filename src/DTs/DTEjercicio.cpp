#include "../../include/DTs/DTEjercicio.h"

string DTEjercicio::getTipo(){
    return tipo;
}
int DTEjercicio :: getIdEjercicio(){
    return idEjercicio;
}

string DTEjercicio :: getDescripcion(){
    return descripcion;
}

string DTEjercicio :: getLetra(){
    return letra;
}

DTEjercicio :: ~DTEjercicio(){
}

DTEjercicio :: DTEjercicio(int idEjercicio, string letra, string descripcion,string tipo,int numLec){
    this->numLec = numLec;
    this->idEjercicio = idEjercicio;
    this->letra = letra;
    this->descripcion = descripcion;
    this->tipo = tipo;
}
