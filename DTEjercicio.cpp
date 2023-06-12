#include "../../include/DTs/DTEjercicio.h"


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

DTEjercicio :: DTEjercicio(int idEjercicio, string letra, string descripcion){
    this->idEjercicio = idEjercicio;
    this->letra = letra;
    this->descripcion = descripcion;
}
