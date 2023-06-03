#include "../../include/DTs/DTEstadisticaProfesor.h"


DTCurso DTEstadisticaProfesor :: getCurso() {
    return Curso;
}

int DTEstadisticaProfesor :: getPromPorcetajesCursos(){
    return promPorcetajesCursos;
}

map<string, int> DTEstadisticaProfesor :: estadoCurso(){
        map<string, int> estadoCur;

        for (i=0; i<this->cursos.size(); i++ ) {
            estado [this->cursos[i]] = this->promPorcetajesCursos[i];

        }

    return estadoCur;
}

DTEstadisticaProfesor :: ~DTEstadisticaProfesor(){

}
       
       
DTEstadisticaProfesor :: DTEstadisticaProfesor(DTCurso Curso, int promPorcetajesCursos){
    this->promPorcetajesCursos = promPorcetajesCursos;
    this->Cursos = cursos;    
}

