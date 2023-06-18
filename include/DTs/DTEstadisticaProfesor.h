#ifndef DTESTADISTICAPROFESOR
#define DTESTADISTICAPROFESOR
#include "../Utils.h"
#include "../DTs/DTCurso.h"

class DTEstadisticaProfesor { 
    private:
        map<string,int> promPorcetajesCursos;
    public:

        DTCurso getCurso();
        map<string,int> getPromPorcetajesCursos(); //Este es un atributo calculado
        
        int estadoCurso(string curso); //CursoClave y valor progreso promedio

        ~DTEstadisticaProfesor();
        DTEstadisticaProfesor();
        DTEstadisticaProfesor(map<string, int> promPorcenCur);

};

#endif