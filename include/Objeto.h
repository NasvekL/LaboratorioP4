#ifndef OBJETO
#define OBJETO
#include "Utils.h"
#include "Ninio.h"


class Objeto
{
private:
    string Nombre;
    int AnioComprado;
    Estado estado;
    Ninio *prestadoA;
public:
    virtual string toString() = 0;
    //getters y setters 
    void setNombre(string);
    void setAnioComprado(int);
    void setEstado(Estado);
    string getNombre();
    int getAnioComprado();
    Estado getEstado();
};


#endif