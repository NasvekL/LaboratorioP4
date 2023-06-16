#ifndef INSCRIPCION
#define INSCRIPCION
#include "../Utils.h"
#include "Curso.h"
#include "Progreso.h"
#include "Estudiante.h"
    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS

class Progreso;
class Curso;
class Estudiante;

class Inscripcion{
    private:
        DTFecha fecha;
        bool aprobado;
        int leccionActual;
        //Pseudoatributos
        Progreso* prog;
        Curso* inscripccionACurso;
        Estudiante* estudianteInscrito;

    public:
        //Getters
        DTFecha getFecha();
        bool getAprobado();
        int getLeccionActual();
        Progreso* getProg();
        Curso* getInscriptoA();
        Estudiante* getEstudiante();

        //Setter
        void setEstudianteInscrito(Estudiante* est);
        void setInscripccionACurso(Curso* curso);

        //Create y destroy
        Inscripcion(DTFecha fecha,Progreso* prog);
        ~Inscripcion();
    
};


#endif