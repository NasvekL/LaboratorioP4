#ifndef RELLENARPALABRAS
#define RELLENARPALABRAS
#include "Utils.h"
#include "Ejercicio.h"

class RellenarPalabras:public Ejercicio{
    private:
        list<string> listaDePalabras;
    public:
        list<string> getlista();
        bool esCorrecto(list<string>);
        void aumentarProgreso(string estudiante);
        RellenarPalabras(list<string> solucion,string letra,int idEjercicio, string descripcion);
};


#endif