#ifndef JUEGOMESA
#define JUEGOMESA
#include "Objeto.h"
#include <string>
using namespace std;

class JuegoMesa: public Objeto{
    private:
        int EdadRecomendada;
        int CantJugadores;
    public:
        //Getters, Setters, Cons y Des
        JuegoMesa();            //Constructor Por Defecto
        JuegoMesa(int edad, int cantidad, string Nombre, int AnioComprado, state estado);    //Constructor -> EdadRecomendada, CantJugadores
        ~JuegoMesa();           
        void setEdadRecomendada(int);
        void setCantJugadores(int);
        int getEdadRecomendada();
        int getCantJugadores();
        
        string toString();
};                   


#endif