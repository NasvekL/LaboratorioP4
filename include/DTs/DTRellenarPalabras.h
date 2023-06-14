#ifndef DTRELLENARPALABRAS
#define DTRELLENARPALABRAS
#include "../Utils.h"
#include "../Clases/Ejercicio.h"

class DTRellenarPalabras{
    private:
        string descripcion;
        int idEjercicio;
        string letra;
        list<string> listaDePalabras;
    public:
        //Getters
        string getDescripcion();
        string getLetra();
        int getIdEjercicio();
        string getListaDePalabras();
        //Create y destroy
        ~DTRellenarPalabras();
        DTRellenarPalabras(string descripcion, string letra, int idEjercicio, list<string> listaDePalabras);
};
#endif