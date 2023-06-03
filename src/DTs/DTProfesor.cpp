#include "../../include/DTs/DTProfesor.h"


string DTProfesor:: getInstituto(){
    return instituto;
}

DTProfesor:: ~Profesor(){

}

DTProfesor::Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto){
    this->nickname=nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->instituto = instituto;
}

// faltan :
        //set<DTNotificacion> verNotificaciones();
        //DTProfesor getDTProfesor();
        //set<DTCurso> obtenerDTCurso();
        //int obtenerPromedio();
        //set<Curso*>& Cursos();
        //set<Idioma*>& Idiomas();

