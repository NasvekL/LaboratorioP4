#include "../include/DTEjercicioConId.h"


int DTEjercicioConId :: getIdEjercicio(){
    return IdEjercicio;
}

string DTEjercicioConId :: getDescripcion(){
    return descripcion;
}

string DTEjercicioConId :: getLetra(){
    return letra;
}

DTEjercicioConId :: ~DTEjercicioConId(){
}

DTEjercicioConId :: DTProfesor(int IdEjercicio, string letra, string descripcion){
    this->IdEjercicio = IdEjercicio;
    this->letra = letra;
    this->descripcion = descripcion;
}
