#include "../../include/DTs/DTCurso.h"



string DTCurso :: getNombre(){
    return nombre;
}

bool DTCurso :: getHabilitado(){
    return habilitado;
}

nivelDeDificultad DTCurso :: getNivel(){
    return nivel;
}

string DTCurso :: getDescripcion(){
    return descripcion;
}

DTCurso :: ~DTCurso(){

}

DTCurso :: DTCurso(string nombre,bool habilitado,nivelDeDificultad nivel,string descripcion){
    this->nombre = nombre;
    this->habilitado = habilitado;
    this->nivel = nivel;
    this->descripcion = descripcion;
}
