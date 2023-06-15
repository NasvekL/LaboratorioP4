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
        int getCantidadDeEjercicios();
        string getObjetivoAprendizaje();
        string getTema();
        void setCantEj(int cant);
        //constructor destructor
        ~DTLeccion();
        DTLeccion(int numero,int cantidadDeEjercicios,string objetivoAprendizaje,string tema);
};
#endif