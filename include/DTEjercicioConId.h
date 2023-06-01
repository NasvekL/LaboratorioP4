#ifndef DTERCICIOCONID
#define DTEJERCICIOCONID
#include "Utils.h"

class DTEjercicioConId { 
    public:
        int IdEjercicio;
        string letra;
        string descripcion;

    private:
        int getIdEjercicio();
        string getDescripcion();
        string getLetra();

        ~DTEjercicioConId();
        DTProfesor(int IdEjercicio, string letra, string descripcion);


};
#endif;