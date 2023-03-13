#ifndef JUEGOMESA
#define JUEGOMESA
#include "Objeto.h"
#include <string>
using namespace std;

class JuegoMesa{
    private:
        int EdadRecomendada;
        int CantJugadores;
    public:
        //Getters, Setters, Cons y Des
        JuegoMesa();            //Constructor Por Defecto
        JuegoMesa(int, int);    //Constructor -> EdadRecomendada, CantJugadores
        ~JuegoMesa();           
        void setEdadRecomendada(int);
        void setCantJugadores(int);
        int getEdadRecomendada();
        int getCantJugadores();
        
        string toString();
};                   


#endif