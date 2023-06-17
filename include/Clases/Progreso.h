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
        //Pseudoatributos
        Inscripcion* inscripcion;
        Leccion* leccionActual;
        list<Ejercicio*> ejerciciosResueltos;
    public:
        virtual bool esCorrecto(string solucion);
        void aumentarProgreso(string estudiante);
        //setters
        void setPorcentaje(int porcentaje);
        void setInscripcion(Inscripcion* insc);
        void setLeccionActual(Leccion* lec);
        //getters
        int getPorcentaje();
        Inscripcion* getInscripcion();
        list<Ejercicio*> getEjerciciosResueltos();
        //constructor destructor
        Progreso(Leccion* lec);
        ~Progreso();
        
};


#endif