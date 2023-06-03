#include "../../include/DTs/DTEstadisticaCurso.h"


String DTEstadisticaCurso :: getCurso(){
    return curso;
}

int DTEstadisticaCurso :: getpromedioCurso(){
    return promedioCurso;
}

DTEstadisticaCurso :: ~DTEstadisticaCurso(){

}
 
DTEstadisticaCurso :: DTEstadisticaCurso(ArrayList<Integer> promedioCurso, ArrayList<String> CursosPropuestos){
    this->promedioCurso = promedioCurso
    this->cursosProppuestos = CursosPropuestos;
}

DTCurso infoCurso(){
    return curso;
}

int DTEstadisticaCurso:: gradoAvance(){
    return promedioCurso;
}
