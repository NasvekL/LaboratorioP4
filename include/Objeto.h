#ifndef Objeto
#define Objeto

#include <string>
using namespace std;

#include "estado.h"

class Objeto
{
private:
    string Nombre;
    int AnioComprado;

public:
    string toString();
};


