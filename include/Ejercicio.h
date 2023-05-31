#ifndef EJERCICIO
#define EJERCICIO
#include "Utils.h"

class Leccion;

class Ejercicio{
    private:
        int idEjercicio;
        string descripcion;
        string letra;
        Leccion * leccion;
    public:
        virtual bool esCorrecto(string solucion);
        void aumentarProgreso(string estudiante);
};


#endif