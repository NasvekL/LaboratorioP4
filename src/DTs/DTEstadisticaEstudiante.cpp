#include "../../include/DTs/DTEstadisticaEstudiante.h"

ArrayList<Integer> DTEstadisticasEstudiante :: getPorcentajes(){
    return porcentajesCursos;
}
        
ArrayList<String> DTEstadisticasEstudiante :: getCursos(){
    return cursos;
}


map<string, int> DTEstadisticaEstudiante :: estadoEstudiante() {

    map<string, int> estado;

        for (i=0; i<this->cursos.size(); i++ ) {
            estado [this->cursos[i]] = this->porcentajesCursos[i];

        }

    return estado;

}

DTEstadisticasEstudiante :: ~DTEstadisticaEstudiante(){
}


DTEstadisticasEstudiante :: DTEstadisticasEstudiante(ArrayList<Integer> porcetajesCursos, ArrayList<String> cursos){
    this->porcentajesCursos = porcentajesCursos;
    this->Cursos = cursos;
}

