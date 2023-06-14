#ifndef RELLENARPALABRAS
#define RELLENARPALABRAS
#include "../Utils.h"
#include "Ejercicio.h"

class RellenarPalabras:public Ejercicio{
    private:
        list<string> listaDePalabras;
    public:
        list<string> getlista();
        bool esCorrectoRellenarPal(list<string>);
        bool esCorrectoTraduccion(string solucion);
        void aumentarProgreso(string estudiante);
        //constructor destructor
        RellenarPalabras(list<string> listaDePalabras,int idEjercicio,string descripcion,string letra,Leccion* Lec);
        ~RellenarPalabras();
};


#endif