#ifndef CURSO
#define CURSO
#include "Utils.h"
#include "DTCurso.h"
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
        set<DTCurso> previas; 
        //Pseudoatributos
        Idioma* idiomaDelCurso;
        Profesor* profesorQueLoDicta;
        set<Leccion*> lecciones;
        set<Inscripcion*> inscripciones;
    public:
        //CONSTRUCTOR Y DESTRUCTOR
        ~Curso();
        Curso(string nombre, string descripcion, nivelDeDificultad nivel, bool habilitado, set<DTCurso> previas);

        //GETTERS
        string getNombreCurso();
        string getDescripcion();
        nivelDeDificultad getNivelDeDificultad();
        bool getHabilitado();
        //SETTERS
        void setHabilitado(bool habilitado);

        //GETTERS DE PSEUDOATRIBUTOS
        Idioma* getIdiomaDelCurso();
        Profesor* getProfesorQueLoDicta();
        set<Leccion*>& getLecciones(); 
        set<Inscripcion*>& getInscripciones();
        //SETTERS DE PSEUDOATRIBUTOS
        void setIdiomaDelCurso(Idioma* i);
        void setProfesorQueLoDicta(Profesor* p);
        void setLecciones(set<Leccion*> lecciones);
        void setInscripciones(set<Inscripcion*> inscripciones);

        //OPERACIONES
        Ejercicio seleccionarEjercicio(int idEjercicio); //Esto iria en controladorCurso me parece
        int progresoPromedio();
        int progresoDeEstudiante(Estudiante e);
        DTestadisticaCurso estadisticasCurso();

        //Obtener Pseudoatributos
        //Faltan los casos de uso que nos den las operaciones de agregar idiomas y cursos
};


#endif