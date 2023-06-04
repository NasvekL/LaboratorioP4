#ifndef DTESTADISTICAPROFESOR
#define DTESTADISTICAPROFESOR
#include "../Utils.h"

class DTCurso;

class DTEstadisticaProfesor { 
    private:
        map<string,int> promPorcetajesCursos;
    public:

        DTCurso getCurso();
        int getPromPorcetajesCursos(); //Este es un atributo calculado

        map<string, int> estadoCurso(); //CursoClave y valor progreso promedio

        ~DTEstadisticaProfesor();
        DTEstadisticaProfesor(string profesor);

};

#endif;