#ifndef OBJETO
#define OBJETO

#include <string>
using namespace std;

#include "Utils.h"

class Objeto
{
private:
    string Nombre;
    int AnioComprado;
    estado;
public:
    Objeto setObjeto(string, int, estado); //Constructor(nombre, anioCreacion, estado|nuevo, bienConservado, roto|)
    ~Objeto(); //Destructor
    string getNombre();
    int getAnioComprado();
    estado getEstado();
    string toString() = 0;
};


#endif