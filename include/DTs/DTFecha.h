#ifndef DTFECHA
#define DTFECHA
#include <string>
using namespace std;

class DTFecha{

    private:
        int dia;
        int mes;
        int anio;


    public:
        int getDia();
        int getMes();
        int getAnio();
        string toString();

        ~DTFecha();
        DTFecha();
        DTFecha(int dia, int mes, int anio);
};
#endif







