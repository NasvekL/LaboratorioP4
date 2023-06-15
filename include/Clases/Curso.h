#ifndef CURSO
#define CURSO
#include "../Utils.h"
#include "../DTs/DTCurso.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTEstadisticaCurso.h"
#include "Estudiante.h"
class Idioma;
class Inscripcion;
class Leccion;
class Profesor;
class Estudiante;
class Ejercicio;
class DTestadisticaCurso;

class Curso{
    private:
        string nombre;
        string descripcion;
        nivelDeDificultad nivelDeDif;
        bool habilitado;
        list<Curso*> previas; 
        //Pseudoatributos
        Idioma* idiomaDelCurso;
        Profesor* profesorQueLoDicta;
        list<Leccion*> lecciones;
        list<Inscripcion*> inscripciones;
    public:
        //CONSTRUCTOR Y DESTRUCTOR
        ~Curso();
        Curso(string nombre, string descripcion, nivelDeDificultad nivel, bool habilitado, list<Curso*> previas, Idioma* idioma, Profesor* profesorQueLoDicta);
        Curso();
        //GETTERS
        string getNombreCurso() const; //se puede poner const para indicar que la funcion no modifica el objeto. Si no c++ se queja despues al buscar curso por nombre
        string getDescripcion();
        nivelDeDificultad getNivelDeDificultad();
        bool getHabilitado();
        list<Curso*> getPrevias();
        //SETTERS
        void setHabilitado(bool habilitado);

        //GETTERS DE PSEUDOATRIBUTOS
        Idioma* getIdiomaDelCurso();
        Profesor* getProfesorQueLoDicta();
        list<Leccion*>& getLecciones(); 
        list<Inscripcion*>& getInscripciones();
        //SETTERS DE PSEUDOATRIBUTOS
        void setIdiomaDelCurso(Idioma* i);
        void setProfesorQueLoDicta(Profesor* p);
        void setLecciones(list<Leccion*> lecciones);
        //void setInscripciones(list<Inscripcion*> inscripciones);
        void agregarInscripcion(Inscripcion* insc);

        //OPERACIONES
        DTEjercicio seleccionarEjercicio(int idEjercicio); //Esto iria en controladorCurso me parece
        int progresoPromedio();
        int progresoDeEstudiante(Estudiante e);
        DTEstadisticaCurso estadisticasCurso();
        void agregarLeccion(Leccion* lec);

        //Obtener Pseudoatributos
        //Faltan los casos de uso que nos den las operaciones de agregar idiomas y cursos
};


#endif