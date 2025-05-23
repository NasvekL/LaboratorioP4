#ifndef ESTUDIANTE
#define ESTUDIANTE
#include "../Utils.h"
#include "Usuario.h"
#include "../DTs/DTEstudiante.h"
#include "../DTs/DTNotificacion.h"
#include "../DTs/DTCurso.h"
#include "../Clases/Inscripcion.h"

    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS
class Curso;
class Leccion;
class Inscripcion;

class Estudiante: public Usuario{
    private:   
        string pais;
        DTFecha nacimiento;
        //Pseudoatributos
        list<Inscripcion*> inscripciones;
    public:
        //Getters y Setters
        string getPais();
        DTFecha getNacimiento();
        list<Inscripcion*> getInscripciones();
        //Create destroy
        ~Estudiante();
        Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha nacimiento);
        //Otras operaciones
        DTEstudiante getDTEstudiante();
        set<string> getCursosInscriptosSA();
        Curso* buscarCurso(string nombreCurso);
        list<DTEjercicio> ejerciciosNoAprobados(string curso);
        //Faltan los casos de uso que me permiten agregar y eliminar inscripciones

        void agregarInscripcion(Inscripcion* insc);
        void eliminarInscripcion(Inscripcion* insc);
};


#endif