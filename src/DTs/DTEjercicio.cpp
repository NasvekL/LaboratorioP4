#include "../../include/DTs/DTEjercicio.h"


int DTEjercicio :: getIdEjercicio(){
    return IdEjercicio;
}

string DTEjercicio :: getDescripcion(){
    return descripcion;
}

string DTEjercicio :: getLetra(){
    return letra;
}

DTEjercicio :: ~DTEjercicio(){
}

DTEjercicio :: DTEjercicio(int IdEjercicio, string letra, string descripcion){
    this->IdEjercicio = IdEjercicio;
    this->letra = letra;
    this->descripcion = descripcion;
}
