#ifndef OBJETO
#define OBJETO
#include "Utils.h"
#include "Ninio.h"


class Objeto
{
private:
    string Nombre;
    int AnioComprado;
    estado estado;
    Ninio *prestadoA;
public:
    virtual string toString() = 0;
    //getters y setters 
    void setNombre(string);
    void setAnioComprado(int);
    void setEstado(estado);
    string getNombre();
    int getAnioComprado();
    estado getEstado();
};


#endif