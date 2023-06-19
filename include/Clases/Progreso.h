#ifndef PROGRESO
#define PROGRESO
#include "../Utils.h"
#include "Ejercicio.h"
#include "Leccion.h"
#include "Inscripcion.h"
class Inscripcion;
class Progreso{
    private:
        int porcentaje;
        int porcentajeCurso;
        //Pseudoatributos
        Inscripcion* inscripcion;
        Leccion* leccionActual;
        list<Ejercicio*> ejerciciosResueltos;
    public:
        void aumentarProgreso(string estudiante);
        //setters
        void setPorcentajeCurso(float porcen);
        void setPorcentaje(float porcentaje);
        void setInscripcion(Inscripcion* insc);
        void setLeccionActual(Leccion* lec);
        void limpiarEjerciciosResueltos();
        void agregarEjercicioResuelto(Ejercicio* e);
        //getters
        int getPorcentaje();
        Inscripcion* getInscripcion();
        list<Ejercicio*> getEjerciciosResueltos();
        int getPorcentajeCurso();
        //constructor destructor
        Progreso(Leccion* lec);
        ~Progreso();
};


#endif