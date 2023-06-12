#ifndef DTEJERCICIO
#define DTEJERCICIO
#include "../Utils.h"

class DTEjercicio { 
    private:
        int idEjercicio;
        string letra;
        string descripcion;
        //si es traduccion
        string solucionTraduccion;
        //si es completarPalabras
        set<string> solucionCompletarPalabras;

    public:
        int getIdEjercicio();
        string getDescripcion();
        string getLetra();

        ~DTEjercicio();
        DTEjercicio(int idEjercicio, string letra, string descripcion);


};
#endif