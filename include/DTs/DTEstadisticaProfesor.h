#ifndef DTESTADISTICAPROFESOR
#define DTESTADISTICAPROFESOR
#include "../Utils.h"
#include "../DTs/DTCurso.h"

class DTEstadisticaProfesor { 
    private:
        map<string,int> promPorcetajesCursos;
    public:
        map<string,int> getPromPorcetajesCursos(); //Este es un atributo calculado
        ~DTEstadisticaProfesor();
        DTEstadisticaProfesor();
        DTEstadisticaProfesor(map<string, int> promPorcenCur);

};

#endif