#ifndef DTLECCION
#define DTLECCION
#include "../Utils.h"
class DTLeccion{
    private:
        int numero;
        int cantidadDeEjercicios;
        string objetivoAprendizaje;
        string tema;
    public:
        //getters
        int getNumero();
        int getCantidadDe1Ejercicios();
        string getObjetivoAprendizaje();
        string getTema();
        //constructor destructor
        ~DTLeccion();
        DTLeccion(int numero,int cantidadDeEjercicios,string objetivoAprendizaje,string tema);
};
#endif