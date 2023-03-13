#ifndef OBJETO
#define OBJETO
#include "Utils.h"

class Objeto
{
private:
    string Nombre;
    int AnioComprado;
    estado;
public:
    string toString() = 0;
    Objeto setObjeto(string, int, estado); //Constructor(nombre, anioCreacion, estado|nuevo, bienConservado, roto|)
    ~Objeto(); //Destructor
    //getters y setters 
    string getNombre();
    int getAnioComprado();
    estado getEstado();
};


#endif