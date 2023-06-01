#ifndef PROFESOR
#define PROFESOR
#include "Utils.h"
#include "Usuario.h"
#include "DTNotificacion.h"
#include "DTProfesor.h"
    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS

class Curso;
class Idioma;

class Profesor: public Usuario{
    private:
        string instituto;
        //Pseudoatributos
        set<Idioma*> idiomas;  
        set<Curso*> cursos;
    public:
        //Getters
        string getInstituto();
        //Create y destroy
        ~Profesor();
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);
        //Otras operaciones
        set<DTNotificacion> verNotificaciones();
        DTProfesor getDTProfesor();
        set<DTCurso> obtenerDTCurso();
        int obtenerPromedio();
        //Obtener Pseudoatributos
        set<Idioma*>& Idiomas();
        set<Curso*>& Cursos();
        //Faltan los casos de uso que nos den las operaciones de agregar idiomas y cursos
};


#endif