#include "../../include/DTs/DTNotificacion.h"


DTCurso DTNotificacion:: getCurso(){
    return cursoCreado;
}

Idioma DTNotificacion:: getIdioma(){
    return idiomaDelCurso;
}

DTNotificacion:: ~DTNotificacion(){

}

DTNotificacion:: DTNotificacion(DTCurso cursoCreado,Idioma idiomaDelCurso){
    this->cursoCreado = cursoCreado;
    this->idiomaDelCurso = idiomaDelCurso;
}

