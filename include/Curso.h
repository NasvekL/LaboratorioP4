#ifndef CURSO
#define CURSO
#include "Utils.h"

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
        nivelDeDificutlad nivelDeDif;
        bool Habilitado;
        Set(DTCurso) previas; 
        //Pseudoatributos
        Idioma* seDictaEn;
        Profesor* loDicta;
        set<Leccion*> lecciones;
        set<Inscripcion*> inscripciones;
    public:
        //Getters
        string getNombreCurso();
        string getDescripcion();
        nivelDeDificutlad getNivelDeDificultad();
        bool getHabilitado();
        //Create y destroy
        ~Curso();
        Curso(string nombre, string descripcion, nivelDeDificutlad nivel, bool habilitado, Set(DTCurso) previas);
        //Otras operaciones
        Ejercicio seleccionar(int idEjercicio);
        int getPromedio(Profesor p);
        int getProgreso(Estudiante e);
        DTestadisticaCurso mostrarEstadisticas();
        //Obtener Pseudoatributos
        Idioma* idiomas();
        Profesor* profesores();
        Set<Leccion*>& lecciones(); 
        Set<Inscripcion*>& inscripciones();
        //Faltan los casos de uso que nos den las operaciones de agregar idiomas y cursos
};


#endif