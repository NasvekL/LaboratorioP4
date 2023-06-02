#ifndef DTERCICIOCONID
#define DTEJERCICIOCONID
#include "Utils.h"

class DTEjercicioConId { 
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

        ~DTEjercicioConId();
        DTProfesor noSeQueHaceEstaOperacionNoTeniaNombre(int IdEjercicio, string letra, string descripcion);//?????


};
#endif;