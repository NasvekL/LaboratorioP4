#ifndef PROGRESO
#define PROGRESO
#include "../Utils.h"
#include "Ejercicio.h"
#include "Leccion.h"
#include "Inscripcion.h"

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
        //getters
        int getPorcentaje();
        //constructor destructor
        Progreso(Leccion* lec);
        ~Progreso();
};


#endif