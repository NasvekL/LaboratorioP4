#ifndef DTERCICIO
#define DTEJERCICIO
#include "Utils.h"
#include "DTProfesor.h"//???????????????

class DTEjercicio { 
    public:
        int IdEjercicio;
        string letra;
        string descripcion;
        //si es traduccion
        string solucionTraduccion;
        //si es completarPalabras
        set<string> solucionCompletarPalabras;

    private:
        int getIdEjercicio();
        string getDescripcion();
        string getLetra();

        ~DTEjercicio();
        DTEjercicio(int IdEjercicio, string letra, string descripcion);


};
#endif;