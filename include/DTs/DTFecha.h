#ifndef DTFECHA
#define DTFECHA
#include "../Utils.h"

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
        DTFecha(int dia, int mes, int anio);
};
#endif;









