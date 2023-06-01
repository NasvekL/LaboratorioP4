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
        bool Habilitado;
        set<DTCurso> previas; 
        //Pseudoatributos
        Idioma* seDictaEn;
        Profesor* loDicta;
        set<Leccion*> lecciones;
        set<Inscripcion*> inscripciones;
    public:
        //Getters
        string getNombreCurso();
        string getDescripcion();
        nivelDeDificultad getNivelDeDificultad();
        bool getHabilitado();
        //Create y destroy
        ~Curso();
        Curso(string nombre, string descripcion, nivelDeDificultad nivel, bool habilitado, Set(DTCurso) previas);
        //Otras operaciones
        Ejercicio seleccionar(int idEjercicio);
        int getPromedio(Profesor p);
        int getProgreso(Estudiante e);
        DTestadisticaCurso mostrarEstadisticas();
        //Obtener Pseudoatributos
        Idioma* idiomas();
        Profesor* profesores();
        set<Leccion*>& lecciones(); 
        set<Inscripcion*>& inscripciones();
        //Faltan los casos de uso que nos den las operaciones de agregar idiomas y cursos
};


#endif