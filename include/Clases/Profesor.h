#ifndef PROFESOR
#define PROFESOR
#include "../Utils.h"
#include "Usuario.h"
#include "Idioma.h"
#include "../DTs/DTNotificacion.h"
#include "../DTs/DTProfesor.h"

class Curso;
class Profesor: public Usuario{
    private:
        string instituto;
        //Pseudoatributos
        set<Idioma*> idiomas;  
        list<Curso*> cursos;
    public:
        //Getters
        string getInstituto();
        //Create y destroy
        ~Profesor();
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto,set<Idioma*> idiomas);
        //Otras operaciones
        DTProfesor getDTProfesor();
        //Obtener Pseudoatributos
        set<Idioma*> getIdiomas();
        list<Curso*> getCursos();
        void agregarCurso(Curso* curso);
        void eliminarCurso(Curso* curso);
        //Faltan los casos de uso que nos den las operaciones de agregar idiomas y cursos
};


#endif