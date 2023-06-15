#ifndef DTTRADUCCION
#define DTTRADUCCION
#include "../Utils.h"
#include "../Clases/Ejercicio.h"

class DTTraduccion{
    private:
        string tipo;
        string descripcion;
        int idEjercicio;
        int numLec;
        string letra;
        string solucion;
    public:
        //Getters
        int getNumLec();
        string getTipo();
        string getDescripcion();
        string getLetra();
        int getIdEjercicio();
        string getSolucion();
        //Create y destroy
        ~DTTraduccion();
        DTTraduccion(string descripcion, string letra, int idEjercicio, string solucion, string tipo,int numLec);
};
#endif