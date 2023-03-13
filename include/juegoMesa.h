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
        JuegoMesa(int, int);    //Constructor -> EdadRecomendada, CantJugadores
        JuegoMesa();
        ~JuegoMesa();           
        string toString();
};                   


#endif