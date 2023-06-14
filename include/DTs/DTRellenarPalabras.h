#ifndef DTRELLENARPALABRAS
#define DTRELLENARPALABRAS
#include "../Utils.h"
#include "../Clases/Ejercicio.h"

class DTRellenarPalabras{
    private:
        string tipo;
        string descripcion;
        int idEjercicio;
        string letra;
        list<string> listaDePalabras;
    public:
        //Getters
        string getTipo();
        string getDescripcion();
        string getLetra();
        int getIdEjercicio();
        set<string> getListaDePalabras();
        //Create y destroy
        ~DTRellenarPalabras() = default;
        DTRellenarPalabras(string descripcion, string letra, int idEjercicio, list<string> listaDePalabras, string tipo);
};
#endif