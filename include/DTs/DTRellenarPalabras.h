#ifndef DTRELLENARPALABRAS
#define DTRELLENARPALABRAS
#include "../Utils.h"
#include "../Clases/Ejercicio.h"

class DTRellenarPalabras{
    private:
        string descripcion;
        int idEjercicio;
        string letra;
        set<string> listaDePalabras;
    public:
        //Getters
        string getDescripcion();
        string getLetra();
        int getIdEjercicio();
        set<string> getListaDePalabras();
        //Create y destroy
        ~DTRellenarPalabras() = default;
        DTRellenarPalabras(string descripcion, string letra, int idEjercicio, set<string> listaDePalabras);
};
#endif