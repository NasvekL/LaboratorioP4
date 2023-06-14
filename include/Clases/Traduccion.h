#ifndef TRADUCCION
#define TRADUCCION
#include "../Utils.h"
#include "Ejercicio.h"

class Traduccion:public Ejercicio{
    private:
        string solucion;

    public:
        string getSolucion();
        bool esCorrectoTraduccion(string solucion);
        void aumentarProgreso(string estudiante);
        Traduccion(string solucion,int idEjercicio,string descripcion,string letra);
        ~Traduccion();
};


#endif