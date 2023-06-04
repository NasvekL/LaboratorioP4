#ifndef PROFESOR
#define PROFESOR
#include "../Utils.h"
#include "Usuario.h"
#include "../DTs/DTNotificacion.h"
#include "../DTs/DTProfesor.h"
    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS

class Curso;
class Idioma;

class Profesor: public Usuario{
    private:
        string instituto;
        //Pseudoatributos
        list<Idioma*> idiomas;  
        list<Curso*> cursos;
    public:
        //Getters
        string getInstituto();
        //Create y destroy
        ~Profesor();
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto,list<Idioma*> idiomas);
        //Otras operaciones
        list<DTNotificacion> verNotificaciones();
        DTProfesor getDTProfesor();
        set<DTCurso> obtenerDTCurso();
        int obtenerPromedio();
        //Obtener Pseudoatributos
        set<Idioma*>& Idiomas();
        set<Curso*>& Cursos();
        //Faltan los casos de uso que nos den las operaciones de agregar idiomas y cursos
};


#endif