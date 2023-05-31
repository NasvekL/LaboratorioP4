#ifndef PROGRESO
#define PROGRESO
#include "Utils.h"


class Progreso{
    private:
        int porcentaje;
        //Pseudoatributos
        //inscripcion : curso
        //leccion: leccion
        //ejercicios: set<ejercicio>
    public:
        virtual bool esCorrecto(string solucion);
        void aumentarProgreso(string estudiante);
};


#endif