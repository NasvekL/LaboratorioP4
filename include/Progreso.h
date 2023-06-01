#ifndef PROGRESO
#define PROGRESO
#include "Utils.h"
#include "Ejercicio.h"
#include "Leccion.h"
#include "Inscripcion.h"

class Progreso{
    private:
        int porcentaje;
        //Pseudoatributos
        Inscripcion* curso
        Leccion* leccion
        ejercicios set<ejercicio>
    public:
        virtual bool esCorrecto(string solucion);
        void aumentarProgreso(string estudiante);
        //setters
        void setPorcentaje(int porcentaje);
        //getters
        int getPorcentaje();
        //constructor destructor
        Progreso(int Porcentaje);
        ~Progreso();
};


#endif