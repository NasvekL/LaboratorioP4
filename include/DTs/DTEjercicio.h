#ifndef DTEJERCICIO
#define DTEJERCICIO
#include "../Utils.h"

class DTEjercicio { 
    private:
        string tipo;
        int idEjercicio;
        int numLec;
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
        string getTipo();
        ~DTEjercicio();
        DTEjercicio(int idEjercicio, string letra, string descripcion,string tipo,int numLec);


};
#endif