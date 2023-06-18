#ifndef DTCURSO
#define DTCURSO
#include "../Utils.h"

class DTCurso{
    private:
        string nombre;
        set<string> previas;
        bool habilitado;
        nivelDeDificultad nivel;
        string descripcion;
    public:
        //getters
        string getNombre();
        set<string> getPrevias();
        bool getHabilitado();
        nivelDeDificultad getNivel();
        string getDescripcion();
        //constructor destructor
        ~DTCurso();
        DTCurso();
        DTCurso(string nombre,bool habilitado,nivelDeDificultad nivel,string descripcion, set<string> previas);

};
#endif