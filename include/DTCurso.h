#ifndef DTCURSO
#define DTCURSO
#include "Utils.h"
class DTCurso{
    private:
        string nombre;
        set<DTCurso> previas;
        bool habilitado;
        nivelDeDificultad nivel;
        string descripcion;
    public:
        //getters
        string getNombre();
        set<DTCurso> getPrevias();
        bool getHabilitado();
        nivelDeDificultad getNivel();
        string getDescripcion();
        //constructor destructor
        ~DTCurso();
        DTCurso(string nombre,bool habilitado,nivelDeDificultad nivel,string descripcion);

};
#endif;