#ifndef TRADUCCION
#define TRADUCCION
#include "../Utils.h"
#include "../Clases/Ejercicio.h"
#include "Leccion.h"

class Traduccion:public Ejercicio{
    private:
        string solucion;

    public:
        string getSolucion();
        bool esCorrectoTraduccion(string solucion);
        bool esCorrectoRellenarPal(list<string> solucion);
        void aumentarProgreso(string estudiante);
        Traduccion(string solucion,int idEjercicio,string descripcion,string letra,Leccion* lec);
        ~Traduccion() = default;
};


#endif