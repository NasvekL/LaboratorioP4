#ifndef FECHA
#define FECHA
#include <string>
using namespace std;

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int dia,int mes,int anio);
        int getDia();
        int getMes();
        int getAnio();
        string toString();
};



#endif