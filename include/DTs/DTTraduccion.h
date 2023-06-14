#ifndef DTTRADUCCION
#define DTTRADUCCION
#include "../Utils.h"
#include "../Clases/Ejercicio.h"

class DTTraduccion{
    private:
        string descripcion;
        int idEjercicio;
        string letra;
        string solucion;
    public:
        //Getters
        string getDescripcion();
        string getLetra();
        int getIdEjercicio();
        string getSolucion();
        //Create y destroy
        ~DTTraduccion() = default;
        DTTraduccion(string descripcion, string letra, int idEjercicio, string solucion);
};
#endif